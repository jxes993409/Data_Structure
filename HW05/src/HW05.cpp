#include <stdio.h>
#include <stdlib.h>
#include "./lib/readfile.h"

int main(int argc, char *argv[])
{
  const char *input_name = *(argv + 1);
  const char *output_name = *(argv + 2);
  int size = 0;

  // read the first line, and calculate the array size
  read_size(input_name, &size);
  printf("%d\n", size);
  // create 2-d array
  int **length_array = new int*[size];
  int *pi = new int[size];
  int *dist = new int[size];
  for(int i = 0; i < size; i++) {length_array[i] = new int[size]();}

  read_file(input_name, size, length_array);
  // Bellman-Ford's Algorithm
  Bellman_Ford_Algorithm(size, pi, dist, length_array);
  // write output
  write_output(output_name, size, pi, dist);

  // free the memory and close the file
  for(int i = 0; i < size; i++) {delete [] length_array[i];}
  delete [] length_array;
  delete [] pi;
  delete [] dist;
  return 0;
}