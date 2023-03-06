#ifndef _READFILE_H_
#define _READFILE_H_

#define MAX_INPUT_LENGTH 20
#define MAX_STRING_SUM 500
#define MAX_ID_LENGTH 28
#define MAX_OUTPUT_LENGTH 50000

typedef struct _hash_table
{
  char *input_string = new char[MAX_INPUT_LENGTH];
  char *string_id = new char[MAX_ID_LENGTH];
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


void read_string(const char [], Hasharray **, Hashaddress **);
void read_target(const char [], const char [], Hasharray **, Hashaddress **);
void find_target(const char [], char [], int, int, Hasharray **, Hashaddress **);
void hash_function(const char [], char *, int *);
void write_output(const char[], const char[]);
Hashtable *create_node(const char [], const char []);
void delete_node(Hashtable *, Hashtable *);

#endif