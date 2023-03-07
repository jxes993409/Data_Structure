#include <stdio.h>
#include <stdlib.h>
#include "./lib/readfile.h"

int main(int argc, char *argv[])
{
  const char *input_string_name = *(argv + 1);
  const char *input_target_name = *(argv + 2);
  const char *output_name = *(argv + 3);

  Hasharray *hash_array = new Hasharray[TABLE_SIZE];
  Hashaddress *hash_address = new Hashaddress[TABLE_SIZE];

  // point the hash_address[i] head and tail to the hash_array[i]'s head
  initialize(hash_array, hash_address);

  // read string.in
  read_string(input_string_name, hash_array, hash_address);
  // read target.in, and find the target
  read_target(input_target_name, output_name, hash_array, hash_address);

  // free the memory and close the file
  for(int i = 0; i < TABLE_SIZE; i++)
  {
    hash_address[i].head = NULL;
    hash_address[i].tail = NULL;
    while(hash_array[i].value->next != NULL) {delete_node(hash_array[i].value->next, hash_array[i].value);}
    delete [] hash_array[i].value->input_string;
    delete [] hash_array[i].value->string_id;
    delete hash_address[i].head;
    delete hash_address[i].tail;
  }
  delete [] hash_array;
  delete [] hash_address;
  return 0;
}