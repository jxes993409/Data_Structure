#include <stdio.h>
#include <stdlib.h>
#include "./lib/readfile.h"

int main(int argc, char *argv[])
{
  const char *input_string_name = *(argv + 1);
  const char *input_target_name = *(argv + 2);
  const char *output_name = *(argv + 3);

  // create 2-d hash array, first diemension store the string length, second diemension store the sum of string
  // 'a' = 0, 'b' = 1, 'c' = 2, ..., 'z' = 25
  // ex: 'abc' = 0 + 1 + 2 = 3, store to hash_array[2][3]
  Hasharray **hash_array = new Hasharray*[MAX_INPUT_LENGTH];
  Hashaddress **hash_address = new Hashaddress*[MAX_INPUT_LENGTH];
  for(int i = 0; i < MAX_INPUT_LENGTH; i++)
  {
    hash_array[i] = new Hasharray[MAX_STRING_SUM];
    hash_address[i] = new Hashaddress[MAX_STRING_SUM];
  }
  // point the hash_address[i][j] head and tail to the hash_array[i][j]'s head
  for(int i = 0; i < MAX_INPUT_LENGTH; i++)
  {
    for(int j = 0; j < MAX_STRING_SUM; j++)
    {
      hash_address[i][j].head = hash_array[i][j].value;
      hash_address[i][j].tail = hash_array[i][j].value;
    }
  }

  read_string(input_string_name, hash_array, hash_address);
  read_target(input_target_name, output_name, hash_array, hash_address);

  // free the memory and close the file
  for(int i = 0; i < MAX_INPUT_LENGTH; i++)
  {
    for(int j = 0; j < MAX_STRING_SUM; j++)
    {
      hash_address[i][j].head = NULL;
      hash_address[i][j].tail = NULL;
      while(hash_array[i][j].value->next != NULL) {delete_node(hash_array[i][j].value->next, hash_array[i][j].value);}
      delete hash_array[i][j].value;
      delete hash_address[i][j].head;
      delete hash_address[i][j].tail;
    }
    delete [] hash_array[i];
    delete [] hash_address[i];
  }
  delete [] hash_array;
  delete [] hash_address;
  return 0;
}