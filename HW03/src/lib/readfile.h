#ifndef _READFILE_H_
#define _READFILE_H_

typedef struct _polynomial
{
	int coef = 0, exp_x = 0, exp_y = 0, exp_z = 0;
  int len = 1, be_calc = 0;
} Polynomial;

typedef struct _list_node
{
  Polynomial value;
  _list_node *next = NULL;
} Listnode;

typedef struct _poly_table
{
  Listnode *address = new Listnode;
  _poly_table *next = NULL;
} Polytable;

typedef struct _poly_address
{
  Listnode *head = new Listnode;
  Listnode *tail = new Listnode;
} Polyaddress;

void read_file(const char [], Listnode *, Polyaddress *, Polytable *);
void write_output(const char[], Listnode *);
void get_num(const char [], int *, int);
void get_coef_exp(const char [], int *);

#endif