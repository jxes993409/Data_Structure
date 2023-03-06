#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "readfile.h"

void read_string(const char input_name[], Hasharray **hash_array, Hashaddress **hash_address)
{
  FILE *input_file = fopen(input_name, "r");
  char *line = new char[MAX_INPUT_LENGTH];

  while((fscanf(input_file, "%[^\n]%*c", line)) != EOF)
  {
    int string_sum = 0;
    char string_id[MAX_ID_LENGTH];
    memset(string_id, 0, size_t(MAX_ID_LENGTH));
    hash_function(line, string_id, &string_sum);
    hash_address[int(strlen(line)) - 1][string_sum].tail->next = create_node(line, string_id);
    hash_address[int(strlen(line)) - 1][string_sum].tail = hash_address[int(strlen(line)) - 1][string_sum].tail->next;
    
  }
  fclose(input_file);
  delete [] line;
}

void read_target(const char input_name[], const char output_name[], Hasharray **hash_array, Hashaddress **hash_address)
{
  FILE *input_file = fopen(input_name, "r");
  char *line = new char[MAX_INPUT_LENGTH];

  while((fscanf(input_file, "%[^\n]%*c", line)) != EOF)
  {
    int string_sum = 0;
    char string_id[MAX_ID_LENGTH];
    char *output_buffer = new char[MAX_OUTPUT_LENGTH]();
    memset(string_id, 0, size_t(MAX_ID_LENGTH));

    hash_function(line, string_id, &string_sum);
    find_target(string_id, output_buffer, int(strlen(line) - 1), string_sum, hash_array, hash_address);
    write_output(output_name, output_buffer);
    delete [] output_buffer;
  }
  fclose(input_file);
  delete [] line;
}

void find_target(const char string_id[], char output_buffer[], int i, int j, Hasharray **hash_array, Hashaddress **hash_address)
{
  int flag = 0;
  hash_array[i][j].value = hash_address[i][j].head;
  if(hash_address[i][j].head != hash_address[i][j].tail)
  {
    hash_array[i][j].value = hash_array[i][j].value->next;
    while(true)
    {
      if(!strcmp(string_id, hash_array[i][j].value->string_id))
      {
        flag = 1;
        strcat(output_buffer, hash_array[i][j].value->input_string);
        strcat(output_buffer, " ");
      }
      if(hash_array[i][j].value->next != NULL) {hash_array[i][j].value = hash_array[i][j].value->next;}
      else {break;}
    }
  }
  if(flag) {strcat(output_buffer, "\n");}
  if(!flag) {strcat(output_buffer, "0\n");}
}

void hash_function(const char line[], char *string_id, int *string_sum)
{
  int *char_count = new int[26]();
  for(int i = 0; i < int(strlen(line)); i++)
  {
    *string_sum = *string_sum + int(line[i]) - 'a';
    char_count[line[i] - 'a']++;
  }
  for(int i = 0; i < 26; i++)
  {
    char temp[1];
    memset(temp, 0, size_t(1));
    temp[0] = char(char_count[i] + 'A');
    strcat(string_id, temp);
  }

  delete [] char_count;
}

void write_output(const char output_name[], const char output_buffer[])
{
  FILE *output_file = fopen(output_name, "a+");
  fprintf(output_file, "%s", output_buffer);
  fclose(output_file);
}

Hashtable *create_node(const char line[], const char string_id[])
{
  Hashtable *new_node = new Hashtable;
  strncpy(new_node->input_string, line, strlen(line));
  strncpy(new_node->string_id, string_id, strlen(string_id));
  new_node->next = NULL;
  return new_node;
}

void delete_node(Hashtable *del_next, Hashtable *del)
{
  // move the next node value to the delete one
  // delete the next node
  memset(del->input_string, 0, size_t(MAX_INPUT_LENGTH));
  memset(del->string_id, 0, size_t(MAX_INPUT_LENGTH));
  strncpy(del->input_string, del_next->input_string, strlen(del_next->input_string));
  strncpy(del->string_id, del_next->string_id, strlen(del_next->string_id));
  del->next = del_next->next;
  delete [] del_next->input_string;
  delete [] del_next->string_id;
  delete del_next;
}