#include "readfile.h"

#ifndef _CALC_H_
#define _CALC_H_

void calc(int, int, int, Listnode *, Polyaddress *, Polytable *);
void print_node(Listnode *, int);
void add_node(int, int, int, int, int, Listnode *, Polyaddress *);
Listnode *create_node(int, int, int, int, int);
Polytable *add_poly_table_node(Listnode *);
void delete_node(Listnode *, Listnode *);
void delete_poly_table_node(Polytable *, Polytable *);
void insert_node(Listnode *, Listnode *, Listnode *);
Listnode *copy(Listnode *, int);

#endif