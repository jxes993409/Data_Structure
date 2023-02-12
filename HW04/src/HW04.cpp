#include <stdio.h>
#include <stdlib.h>
#include "./lib/readfile.h"

int main(int argc, char *argv[])
{
  const char *input_name = *(argv + 1);
  const char *output_name = *(argv + 2);
  int *heap = new int[MAX_SIZE]{0};
  read_file(input_name, output_name, heap);
  delete heap;
  return 0;
}