#include <stdio.h>
#include <stdlib.h>
#include "./lib/readfile.h"

int main(int argc, char *argv[])
{
  const char *input_name = *(argv + 1);
  const char *output_name = *(argv + 2);
  Polynomial *poly = new Polynomial;
  poly->next = NULL;
  read_file(input_name, poly);
  write_output(output_name, poly);
  // while(true)
  // {
  //   if(output_poly != NULL) printf("%d %d %d %d\n", output_poly->coef, output_poly->exp_x, output_poly->exp_y, output_poly->exp_z);
  //   else break;
  //   output_poly = output_poly->next;
  // }
  // write_output(output_name, processor_num, processor);
  // for(int i = 0; i < processor_num; i++)
  // {
  //   delete [] processor[i].pq;
  //   delete [] processor[i].ts;
  // }
  return 0;
}