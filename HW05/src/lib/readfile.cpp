#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "readfile.h"

void read_size(const char input_name[], int *size)
{
  FILE *input_file = fopen(input_name, "r");
  char *line = new char[300];

  fscanf(input_file, "%[^\n]%*c", line);
  for(int i = 0; i < int(strlen(line)); i++)
  {
    if(line[i] == ' ') {*size = *size + 1;}
  }

  // free the memory and close the file
  delete [] line;
  fclose(input_file);
}

void read_file(const char input_name[], int size, int **length_array)
{
  FILE *input_file = fopen(input_name, "r");
  char *line = new char[300];
  
  for(int i = 0; i < size; i++)
  {
    fscanf(input_file, "%[^\n]%*c", line);
    get_num(line, length_array[i]);
  }

  // free the memory and close the file
  delete [] line;
  fclose(input_file);
}

void write_output(const char output_name[], int size, int *pi, int *dist)
{
  FILE *output_file = fopen(output_name, "w");
  // do not have negative cycle
  if(!dist[0])
  {
    char output_buffer[300];
    int dist_temp;
    for(int i = 1; i < size; i++)
    {
      // clear the output buffer
      memset(output_buffer, 0, size_t(300));
      int count = 0, index = i;
      output_buffer[count++] = '\n';

      if(dist[i] < 0) {dist_temp = -dist[i];} // dist[i] < 0
      else if(!dist[i]) {output_buffer[count++] = '0';} // dist[i] == 0, store '0' to the buffer
      else {dist_temp = dist[i];} // dist[i] > 0

      while(dist_temp != 0)
      {
        output_buffer[count++] = char(dist_temp % 10) + '0'; // store the last bit to the buffer
        dist_temp /= 10;
      }
      if(dist[i] < 0) {output_buffer[count++] = '-';} // dist[i] < 0, store '-' to the buffer
      output_buffer[count++] = ' ';

      while(pi[index] != -1)
      {
        // let pi_temp = index (first time is i)
        int pi_temp = index;
        while(pi_temp != 0)
        {
          output_buffer[count++] = char(pi_temp % 10) + '0'; // store the last bit to the buffer
          pi_temp /= 10;
        }
        output_buffer[count++] = '-';
        index = pi[index]; // let index = pi[index] (the predecessor)
      }
      output_buffer[count++] = '0';
      for(int j = int(strlen(output_buffer)) - 1; j >= 0; j--) {fprintf(output_file, "%c", output_buffer[j]);}
    }
  }
  // have negative cycle
  else
  {
    int *cycle_stack = new int[size]();
    int count = -1, index, flag = 0;
    cycle_stack[++count] = size - 1; // store the last node first
    for(int i = size - 1; ; i = pi[i])
    {
      // check whether the stack has cycle or not
      // If yes, then store the node and the index, and break the loop
      for(int j = 0; j < count; j++)
      {
        if(pi[i] == cycle_stack[j])
        {
          cycle_stack[++count] = pi[i];
          index = j;
          flag = 1;
          break;
        }
      }
      if(flag) {break;}
      cycle_stack[++count] = pi[i]; // store pi[index] (the predecessor)
    }
    for(int i = count; i >= index; i--)
    {
      if(i == index) {fprintf(output_file, "%d\n", cycle_stack[i]);}
      else {fprintf(output_file, "%d-", cycle_stack[i]);}
    }
    delete [] cycle_stack;
  }
  fclose(output_file);
}

void get_num(const char line[], int *length_array)
{
  int char_index = 0, array_index = 0;
  char num_char[5];
  memset(num_char, 0, size_t(5));
  for(int i = 0; i < int(strlen(line)); i++)
  {
    if(line[i] == '-' || isdigit(line[i])) {num_char[char_index++] = line[i];}
    // if line[i] = ' ', convert the string to int and clear the string
    else if(line[i] == ' ')
    {
      length_array[array_index++] = atoi(num_char);
      memset(num_char, 0, size_t(5));
      char_index = 0;
    }
  }
}

void Bellman_Ford_Algorithm(int size, int *pi, int *dist, int **length_array)
{
  // initialize pi and dist array
  for(int i = 0; i < size; i++)
  {
    pi[i] = -1;
    dist[i] = INFINITE_LENGTH;
  }
  dist[0] = 0;

  for(int k = 1; k < size; k++)
  {
    // for each <i, j> belongs to E
    for(int i = 0; i < size; i++)
    {
      for(int j = 0; j < size; j++)
      {
        if(!length_array[i][j]) {continue;}
        // if dist[j] is longer than dist[i] + <i, j>, then update the path
        if(dist[i] + length_array[i][j] < dist[j])
        {
          dist[j] = dist[i] + length_array[i][j];
          pi[j] = i;
        }
      }
    }
  }
}