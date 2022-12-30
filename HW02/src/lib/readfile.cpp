#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readfile.h"

Processor_Queue* read_file(const char filename[], int *processor_num)
{
  FILE *input_file = fopen(filename, "r");
  char *line = new char[15];
  int processor_id;
  char task_name;
  // read the processor number first
  fscanf(input_file, "%[^\n]%*c", line);
  *processor_num = atoi(line);
  Processor_Queue *processor = new Processor_Queue[*processor_num];

  while((fscanf(input_file, "%[^\n]%*c", line)) != EOF)
  {
    // ASSIGN
    if(line[0] == 'A')
    {
      processor_id = get_processor_id(line, int(strlen(line)));
      task_name = get_task_name(line, int(strlen(line)));
      // printf("ASSIGN %d %c\n", processor_id, task_name);
      assign(processor_id - 1, task_name, processor);
    }
    // EXEC
    else if(line[0] == 'E')
    {
      processor_id = get_processor_id(line, int(strlen(line)));
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