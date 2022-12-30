#include <ctype.h>
#include <stdlib.h>
#include <string.h>

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
  char processor_id_char[2];
  // clear string
  memset(processor_id_char, 0, size_t(2));
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