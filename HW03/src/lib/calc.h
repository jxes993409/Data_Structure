#include "readfile.h"

#ifndef _CALC_H_
#define _CALC_H_

void calc(int, int, int, Listnode *, Polyaddress *, Polytable *);
void print_node(Listnode *);
void swap_coef_exp(Listnode *, Listnode *);
void bubble_sort(Listnode *, int, int);
void add_node(int, int, int, int, int, Listnode *, Polyaddress *);
Listnode *create_node(int, int, int, int, int);
Polytable *add_poly_table_node(Listnode *);
void delete_node(Listnode *, Listnode *);
void delete_poly_table_node(Polytable *, Polytable *);
Listnode *copy(Listnode *, int);

#endif