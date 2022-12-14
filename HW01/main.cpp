#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 10000

// void Read_File(const char [], temp_matrix *, temp_matrix *);

typedef struct
{
  int row_num = -1;
  int column_num = 0;
  int *value = new int[MAX_SIZE];
} temp_matrix;

void Read_File(const char filename[], temp_matrix *A, temp_matrix *B)
{
  FILE *input_file = fopen(filename, "r");
  char *c = new char[10];
  int index, flag;

  while((fscanf(input_file, "%c", c)) != EOF)
  {
    if(strcmp("A", c) == 0)
    {
      flag = 0;
      index = 0;
      fscanf(input_file, "%c", c);
    }
    else if(strcmp("B", c) == 0)
    {
      flag = 1;
      index = 0;
      fscanf(input_file, "%c", c);
    }
    else if(strcmp(";", c) == 0)
    {
      if(!flag) {A -> row_num++;}
      else {B -> row_num++;}
    }
    else if(strcmp("-", c) == 0)
    {
      fscanf(input_file, "%[0-9]", c);
      if(!flag)
      {
        A -> value[index] = -atoi(c);
        A -> column_num++;
        index++;
      }
      else
      {
        B -> value[index] = -atoi(c);
        B -> column_num++;
        index++;
      }

    }
    else if(fscanf(input_file, "%[0-9]", c))
    {
      if(!flag)
      {
        A -> value[index] = atoi(c);
        A -> column_num++;
        index++;
      }
      else
      {
        B -> value[index] = atoi(c);
        B -> column_num++;
        index++;
      }
    }
  }
  delete [] c;
  fclose(input_file);
}

void ToMatrix(int **Array)
{

}

int main()
{
  temp_matrix A, B;
  Read_File("Sample_Input", &A, &B);
  A.column_num /= A.row_num;
  B.column_num /= B.row_num;
  int *A_array = new int[A.row_num]();

  for(int i = 0; i < A.column_num; i++)
    printf("%3d ", A.value[i]);
  printf("\n");
  for(int i = 0; i < B.column_num; i++)
    printf("%3d ", B.value[i]);
  printf("\n");
  return 0;
}

