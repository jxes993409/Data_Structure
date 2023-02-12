#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "readfile.h"

void read_file(const char input_name[], const char output_name[], int *heap)
{
  FILE *input_file = fopen(input_name, "r");
  char *line = new char[50];
  int size = 0;

  while((fscanf(input_file, "%[^\n]%*c", line)) != EOF)
  {
    // Operation ID: 0
    if(line[0] == '0')
    {
      int num;
      size++;
      get_num(line, &num);
      insert_node(heap, size, num);
    }
    // Operation ID: 1 (delete)
    else if(line[0] == '1')
    {
      delete_root(heap, size);
      size--;
    }
    // Operation ID: 2 (output with level-order)
    else if(line[0] == '2') {write_output(output_name, heap, size, 2);}
    // Operation ID: 3 (output with pre-order)
    else if(line[0] == '3') {write_output(output_name, heap, size, 3);}
    // Operation ID: 4 (output with in-order)
    else if(line[0] == '4') {write_output(output_name, heap, size, 4);}
    // Operation ID: 5 (output with post-order)
    else if(line[0] == '5') {write_output(output_name, heap, size, 5);}
  }
  // free the memory and close the file
  delete [] line;
  fclose(input_file);
}

void insert_node(int *heap, int size, int num)
{
  // new node >= parent node, swap new node and parent node
  heap[size] = num;
  while(heap[size] >= heap[size / 2] && size > 1)
  {
    swap(&heap[size], &heap[size / 2]);
    size /= 2;
  }
}

void delete_root(int *heap, int size)
{
  int index = 1;
  heap[1] = heap[size];
  while((heap[index] < heap[index * 2] || heap[index] < heap[index * 2 + 1]) && (index * 2) < size)
  {
    // left node >= right node, swap parent and left node
    if(heap[index * 2] >= heap[index * 2 + 1])
    {
      swap(&heap[index], &heap[index * 2]);
      index *= 2;
    }
    // left node < right node, swap parent and right node
    else
    {
      swap(&heap[index], &heap[index * 2 + 1]);
      index = index * 2 + 1;
    }
  }
}

void swap(int *x, int *y)
{
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void write_output(const char output_name[], int *heap, int size, int operation_id)
{
  FILE *output_file = fopen(output_name, "a");
  switch(operation_id)
  {
    case 2: // level-order
      for(int i = 1; i <= size; i++) {fprintf(output_file, "%d ", heap[i]);}
      fprintf(output_file, "\n");
      break;
    case 3: // pre-order
      preorder(output_file, heap, size, 1);
      fprintf(output_file, "\n");
      break;
    case 4: // in-order
      inorder(output_file, heap, size, 1);
      fprintf(output_file, "\n");
      break;
    case 5: // post-order
      postorder(output_file, heap, size, 1);
      fprintf(output_file, "\n");
      break;
    default:
      break;
  }
  fclose(output_file);
}

void preorder(FILE *output_file, int *heap, int size, int index)
{
  if(index <= size)
  {
    fprintf(output_file, "%d ", heap[index]); // middle
    preorder(output_file, heap, size, index * 2); // left
    preorder(output_file, heap, size, index * 2 + 1); // right
  }
}

void inorder(FILE *output_file, int *heap, int size, int index)
{
  if(index <= size)
  {
    inorder(output_file, heap, size, index * 2); // left
    fprintf(output_file, "%d ", heap[index]); // middle
    inorder(output_file, heap, size, index * 2 + 1); // right
  }
}

void postorder(FILE *output_file, int *heap, int size, int index)
{
  if(index <= size)
  {
    postorder(output_file, heap, size, index * 2); // left
    postorder(output_file, heap, size, index * 2 + 1); // right
    fprintf(output_file, "%d ", heap[index]); // middle
  }
}

void get_num(const char line[], int *num)
{
  int i = 2, size = 0;
  char num_char[10];
  memset(num_char, 0, size_t(10));
  for(; i < int(strlen(line)); i++)
  {
    if(line[i] == '-' || isdigit(line[i])) {num_char[size++] = line[i];}
  }
  *num = atoi(num_char);
}