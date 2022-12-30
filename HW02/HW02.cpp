#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "readfile.h"

void ASSIGN(int, char);
void EXE(int);
int get_processor_id(char [], int);
char get_task_name(char [], int);

void read_file(const char filename[])
{
  FILE *input_file = fopen(filename, "r");
  char *line = new char[15];
  size_t len = 0;
  int processor;
  char task_id;
  while((getline(&line, &len, input_file)) != EOF)
  {
    if(isdigit(*line))
    {
      printf("%s\n", line);
    }
    else if(line[0] == 'A')
    {
      processor = get_processor_id(line, strlen(line));
      task_id = get_task_name(line, strlen(line));
      printf("ASSIGN %d %c\n", processor, task_id);
      // ASSIGN(processor, *c);
    }
    else if(line[0] == 'E')
    {
      processor = get_processor_id(line, strlen(line));
      printf("EXEC %d\n", processor);
      // EXE(processor);
    }
    else if(line[0] == 'S') {break;}
  }
  // free the memory and close the file
  delete [] line;
  fclose(input_file);
}

int main(int argc, char *argv[])
{
  const char *input_name = *(argv + 1);
  const char *output_name = *(argv + 2);
  read_file(input_name);
  return 0;
}

int get_processor_id(char line[], int len)
{
  int id;
  int count = 0, flag = 0;
  for(int i = 0; i < len; i++)
  {
    if(isdigit(line[i]))
    {
      count++;
      flag = i;
    }
  }
  char *processor_id = new char[3];
  for(int i = 0; i < count; i++)
  {
    processor_id[i] = line[flag - count + i + 1];
  }
  id = atoi(processor_id);
  delete [] processor_id;
  return id;
}

char get_task_name(char line[], int len)
{
  char task;
  for(int i = 6; i < len; i++)
  {
    if(isalpha(line[i])) {task = line[i];}
  }
  return task;
}