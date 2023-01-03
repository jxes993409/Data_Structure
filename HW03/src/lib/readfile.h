#ifndef _READFILE_H_
#define _READFILE_H_

typedef struct _polynomial
{
	int coef = 0, exp_x = 0, exp_y = 0, exp_z = 0;
  int len = 1, be_calc = 0;
  _polynomial *next;
} Polynomial;

void read_file(const char [], Polynomial *);
void write_output(const char[], Polynomial *);
void get_num(const char [], int *, int);
void get_coef_exp(const char [], int *);
void add_node(int, int *, Polynomial *);

#endif