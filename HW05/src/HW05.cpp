#include <stdio.h>
#include <stdlib.h>
#include "./lib/readfile.h"

int main(int argc, char *argv[])
{
  const char *input_name = *(argv + 1);
  const char *output_name = *(argv + 2);
  read_file(input_name, output_name);
  return 0;
}