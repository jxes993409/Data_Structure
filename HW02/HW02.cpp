#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "readfile.h"
#include "get_id_name.h"
#include "execute.h"

int main(int argc, char *argv[])
{
  const char *input_name = *(argv + 1);
  const char *output_name = *(argv + 2);
  int processor_num;
  Processor_Queue *processor;
  processor = read_file(input_name, &processor_num);
  write_output(output_name, processor_num, processor);
  for(int i = 0; i < processor_num; i++)
  {
    delete [] processor[i].pq;
    delete [] processor[i].ts;
  }
  return 0;
}

Processor_Queue* read_file(const char filename[], int *processor_num)
{
  FILE *input_file = fopen(filename, "r");
  char *line = new char[15];
  size_t len = 0;
  int processor_id;
  char task_name;
  // read the processor number first
  getline(&line, &len, input_file);
  *processor_num = atoi(line);
  Processor_Queue *processor = new Processor_Queue[*processor_num];

  while((getline(&line, &len, input_file)) != EOF)
  {
    // ASSIGN
    if(line[0] == 'A')
    {
      processor_id = get_processor_id(line, strlen(line));
      task_name = get_task_name(line, strlen(line));
      // printf("ASSIGN %d %c\n", processor_id, task_name);
      assign(processor_id - 1, task_name, processor);
    }
    // EXEC
    else if(line[0] == 'E')
    {
      processor_id = get_processor_id(line, strlen(line));
      // printf("EXEC %d\n", processor_id);
      exec(processor_id - 1, *processor_num, processor);
    }
    // STOP
    else if(line[0] == 'S') {break;}
  }
  // free the memory and close the file
  delete [] line;
  fclose(input_file);
  return processor;
}

void write_output(const char filename[], int processor_num, Processor_Queue *processor)
{
  FILE *output_file = fopen(filename, "w");
  fprintf(output_file, "Queuing\n");
  for(int i = 0; i < processor_num; i++)
  {
    fprintf(output_file, "%2d ", i + 1);
    for(int j = processor[i].rear; j < processor[i].front; j++)
    {
      fprintf(output_file, "%c", processor[i].pq[j]);
    }
    fprintf(output_file, "\n");
  }
  fprintf(output_file, "Executed\n");
  for(int i = 0; i < processor_num; i++)
  {
    fprintf(output_file, "%2d ", i + 1);
    for(int j = 0; j <= processor[i].top; j++)
    {
      fprintf(output_file, "%c", processor[i].ts[j]);
    }
    fprintf(output_file, "\n");
  }
  fclose(output_file);
}

int get_processor_id(char line[], int len)
{
  int processor_id;
  int count = 0, index = 0;
  // if 0 - 9, count +1, and store the last number index
  for(int i = 0; i < len; i++)
  {
    if(isdigit(line[i]))
    {
      count++;
      index = i;
    }
  }
  // 0 < processor_num < 100, the number of digits < 3
  char *processor_id_char = new char[2];
  for(int i = 0; i < count; i++)
  {
    // ex
    // 0 1 2 3 4 5 6 7 8
    // A S S I G N   1 9
    // index = 8, count = 2
    // i = 0,
    // index - count + i + 1 
    // = 8 - 2 + 0 + 1
    // = 7
    // processor_id_char[0] = '1'
    // i = 1,
    // index - count + i + 1
    // = 8 - 2 + 1 + 1
    // = 8
    // processor_id_char[1] = '9'
    processor_id_char[i] = line[index - count + i + 1];
  }
  // char to int
  processor_id = atoi(processor_id_char);
  // free the memory
  delete [] processor_id_char;
  return processor_id;
}

char get_task_name(char line[], int len)
{
  // start at i = 6, scan after 'ASSIGN'
  // 0 1 2 3 4 5 6 7 8
  // A S S I G N   1 9
  char task_name;
  for(int i = 6; i < len; i++)
  {
    if(isalpha(line[i]))
    {
      task_name = line[i];
    }
  }
  return task_name;
}

void assign(int processor_id, char task_name, Processor_Queue *processor)
{
  int *front;
  front = &processor[processor_id].front;
  // queue_is_full();
  if(*front > MAX_TASK)
  {
    fprintf(stderr,"Too Many Task!\n");
    exit(EXIT_FAILURE);
  }
  // push();
  processor[processor_id].pq[*front] = task_name;
  *front = *front + 1;
}

void exec(int processor_id, int processor_num, Processor_Queue *processor)
{
  int *rear, *front, *top;
  int max_queue = 0, max_queue_index = -1;
  rear = &processor[processor_id].rear;
  front = &processor[processor_id].front;
  top = &processor[processor_id].top;
  // queue_is_empty();
  if(*rear == *front)
  {
    // rule step 1 and 2, find the smallest pocessor ID(2) which has maximum number of queueing tasks(1)
    for(int i = processor_num - 1; i >= 0; i--)
    {
      if((processor[i].front - processor[i].rear) >= max_queue)
      {
        max_queue = processor[i].front - processor[i].rear;
        max_queue_index = i;
      }
    }
    // rule step 3
    *top = *top + 1;
    processor[processor_id].ts[*top] = processor[max_queue_index].pq[--processor[max_queue_index].front];
  }
  // pop();
  else
  {
    *top = *top + 1;
    processor[processor_id].ts[*top] = processor[processor_id].pq[*rear];
    *rear = *rear + 1;
  }
}