#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "readfile.h"

void initialize(Hasharray *hash_array, Hashaddress *hash_address)
{
  for(int i = 0; i < TABLE_SIZE; i++)
  {
    hash_address[i].head = hash_array[i].value;
    hash_address[i].tail = hash_array[i].value;
  }
}

void read_string(const char input_name[], Hasharray *hash_array, Hashaddress *hash_address)
{
  FILE *input_file = fopen(input_name, "r");
  char *line = new char[MAX_INPUT_LENGTH + 1];

  while((fscanf(input_file, "%[^\n]%*c", line)) != EOF)
  {
    unsigned int hash_index;
    // string_id store the number of every alphabet
    // ex: abcc, count[a] = 1, count[b] = 1, count[c] = 2 => A = 0, B = 1, C = 2, ..., U = 20
    // string_id = "BBCAAAAAAAAAAAAAAAAAAAAAAA"
    char string_id[MAX_ID_LENGTH];
    // clear the string_id
    memset(string_id, 0, size_t(MAX_ID_LENGTH + 1));
    // compute the string_id and hash_value
    hash_index = hash_function(line, string_id);
    hash_address[hash_index].tail->next = create_node(line, string_id); // store the last node to the tail
    hash_address[hash_index].tail = hash_address[hash_index].tail->next; // update the tail
  }
  fclose(input_file);
  delete [] line;
}

void read_target(const char input_name[], const char output_name[], Hasharray *hash_array, Hashaddress *hash_address)
{
  FILE *input_file = fopen(input_name, "r");
  FILE *output_file = fopen(output_name, "a+");
  char *line = new char[MAX_INPUT_LENGTH];

  while((fscanf(input_file, "%[^\n]%*c", line)) != EOF)
  {
    unsigned int hash_index;
    char string_id[MAX_ID_LENGTH];
    char *output_buffer = new char[MAX_OUTPUT_LENGTH]();
    memset(string_id, 0, size_t(MAX_ID_LENGTH + 1));
    hash_index = hash_function(line, string_id);
    find_target(string_id, output_buffer, hash_index, hash_array, hash_address);
    fprintf(output_file, "%s", output_buffer);
    delete [] output_buffer;
  }
  fclose(input_file);
  fclose(output_file);
  delete [] line;
}

void find_target(const char string_id[], char output_buffer[], int hash_index, Hasharray *hash_array, Hashaddress *hash_address)
{
  int flag = 0;
  // point the hash_array to the head
  hash_array[hash_index].value = hash_address[hash_index].head;
  // if head = tail, the chain is empty
  if(hash_address[hash_index].head != hash_address[hash_index].tail)
  {
    hash_array[hash_index].value = hash_array[hash_index].value->next;
    while(true)
    {
      if(strlen(string_id) == strlen(hash_array[hash_index].value->string_id)) // compare the length
      {
        if(!strcmp(string_id, hash_array[hash_index].value->string_id)) // compare the string_id
        {
          flag = 1; // find the target, set the flag
          strcat(output_buffer, hash_array[hash_index].value->input_string); // store the string to buffer
          strcat(output_buffer, " ");
        }
      }
      if(hash_array[hash_index].value->next != NULL) {hash_array[hash_index].value = hash_array[hash_index].value->next;} // chain = chain->next
      else {break;}
    }
  }
  if(flag) {strcat(output_buffer, "\n");}
  if(!flag) {strcat(output_buffer, "0\n");} //if flag = 0, did not find the target, output 0
}

unsigned int hash_function(const char line[], char *string_id)
{
  int prime_table[26] = {677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 767,
                         769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857};
  int char_count[26] = {0};
  long long unsigned int hash_value = 1;
  for(size_t i = 0; i < strlen(line); i++)
  {
    hash_value *= prime_table[line[i] - 'a'];
    char_count[line[i] - 'a']++; // the number of every alphabet
  }
  for(int i = 0; i < 26; i++)
  {
    char temp[1];
    temp[0] = char(char_count[i] + 'A'); // if char_count[2] = 3 => the number of c is 3, char(3 + 'A') = D
    strcat(string_id, temp);
  }
  return ((hash_value % (TABLE_SIZE * 2)) - 1) / 2;
}

Hashtable *create_node(const char line[], const char string_id[])
{
  Hashtable *new_node = new Hashtable;
  strncpy(new_node->input_string, line, strlen(line) + 1);
  strncpy(new_node->string_id, string_id, strlen(string_id) + 1);
  new_node->next = NULL;
  return new_node;
}

void delete_node(Hashtable *del_next, Hashtable *del)
{
  // move the next node value to the delete one
  // delete the next node
  memset(del->input_string, 0, size_t(MAX_INPUT_LENGTH + 1));
  memset(del->string_id, 0, size_t(MAX_INPUT_LENGTH + 1));
  strncpy(del->input_string, del_next->input_string, strlen(del_next->input_string) + 1);
  strncpy(del->string_id, del_next->string_id, strlen(del_next->string_id) + 1);
  del->next = del_next->next;
  delete [] del_next->input_string;
  delete [] del_next->string_id;
  delete del_next;
}