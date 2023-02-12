#ifndef _READFILE_H_
#define _READFILE_H_

#define MAX_SIZE 10000

void read_file(const char [], const char [], int *);
void insert_node(int *, int, int);
void delete_root(int*, int);
void swap(int *, int *);
void write_output(const char[], int *, int, int);
void preorder(FILE *, int *, int, int);
void inorder(FILE *, int *, int, int);
void postorder(FILE *, int *, int, int);
void get_num(const char [], int *);

#endif