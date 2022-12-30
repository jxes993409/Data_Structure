#include "./lib/readfile.h"
#include "./lib/get_id_name.h"
#include "./lib/execute.h"

int main(int argc, char *argv[])
{
  const char *input_name = *(argv + 1);
  const char *output_name = *(argv + 2);
  int processor_num;
  Processor_Queue *processor;
  processor = read_file(input_name, &processor_num);
  write_output(output_name, processor_num, processor);
  for(int i = 0; i < processor_num; i++)
  {
    delete [] processor[i].pq;
    delete [] processor[i].ts;
  }
  return 0;
}