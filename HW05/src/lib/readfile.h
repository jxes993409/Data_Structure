#ifndef _READFILE_H_
#define _READFILE_H_

#define MAX_SIZE 100
#define INFINITE_LENGTH 10000

void read_size(const char [], int *);
void read_file(const char [], int, int **);
void write_output(const char[], int, int *, int *);
void Bellman_Ford_Algorithm(int, int*, int *, int **);
void get_num(const char [], int *);

#endif