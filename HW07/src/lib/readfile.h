#ifndef _READFILE_H_
#define _READFILE_H_

#define TABLE_SIZE 50000
#define MAX_INPUT_LENGTH 20
#define MAX_ID_LENGTH 26
#define MAX_OUTPUT_LENGTH 25000

typedef struct _hash_table
{
  char *input_string = new char[MAX_INPUT_LENGTH + 1];
  char *string_id = new char[MAX_ID_LENGTH + 1];
  _hash_table *next = NULL;
} Hashtable;

typedef struct _hash_array
{
  Hashtable *value = new Hashtable;
} Hasharray;

typedef struct _hash_address
{
  Hashtable *head = new Hashtable;
  Hashtable *tail = new Hashtable;
} Hashaddress;

void initialize(Hasharray *, Hashaddress *);
void read_string(const char [], Hasharray *, Hashaddress *);
void read_target(const char [], const char [], Hasharray *, Hashaddress *);
void find_target(const char [], char [], int, Hasharray *, Hashaddress *);
unsigned int hash_function(const char [], char *);
Hashtable *create_node(const char [], const char []);
void delete_node(Hashtable *, Hashtable *);

#endif