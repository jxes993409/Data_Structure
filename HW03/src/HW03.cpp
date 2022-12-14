#include <stdio.h>
#include <stdlib.h>
#include "./lib/readfile.h"
#include "./lib/calc.h"

int main(int argc, char *argv[])
{
  const char *input_name = *(argv + 1);
  const char *output_name = *(argv + 2);
  Listnode *poly = new Listnode;
  Polyaddress *poly_address = new Polyaddress;
  Polytable *poly_table = new Polytable;
  poly_address->head = poly;
  poly_address->tail = poly;
  poly_table->address = poly;
  read_file(input_name, poly, poly_address, poly_table);
  write_output(output_name, poly->next);
  while(poly_table->next != NULL) {delete_poly_table_node(poly_table->next, poly_table);}
  while(poly->next != NULL) {delete_node(poly->next, poly);}
  delete poly;
  delete poly_table;
  delete poly_address;
  return 0;
}