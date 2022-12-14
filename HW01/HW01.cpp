#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 10000

typedef struct
{
  int row_num = -1;
  int column_num = 0;
  int *value = new int[MAX_SIZE];
} Temp_Matrix;

typedef struct
{
  int row_num;
  int column_num;
  int **Matrix;
} C_Matrix_Struct;

void Read_File(const char [], Temp_Matrix *, Temp_Matrix *);
void Write_Output(const char [], C_Matrix_Struct);
int** To_Matrix(Temp_Matrix *);
int** Generate_Transpose_Matrix(int, int, int **);
int Matrix_Condition(int, int, int, int);
C_Matrix_Struct Generate_C(int, int, int, int, int);
void Cal_Matrix(int, int, int, int **, int **, int **);

int main(int argc, char *argv[])
{
  const char *input_name = *(argv + 1);
  const char *output_name = *(argv +2);
  Temp_Matrix A, B;
  Read_File(input_name, &A, &B);
  int **A_Matrix = To_Matrix(&A);
  int **B_Matrix = To_Matrix(&B);
  int **AT_Matrix = Generate_Transpose_Matrix(A.row_num, A.column_num, A_Matrix);
  int **BT_Matrix = Generate_Transpose_Matrix(B.row_num, B.column_num, B_Matrix);
  int condition = Matrix_Condition(A.row_num, A.column_num, B.row_num, B.column_num);
  C_Matrix_Struct C_Matrix = Generate_C(condition, A.row_num, A.column_num, B.row_num, B.column_num);
  switch(condition)
  {
    case 0:
      Cal_Matrix(A.row_num, A.column_num, B.column_num, A_Matrix, B_Matrix, C_Matrix.Matrix);
      break;

    case 1:
      Cal_Matrix(A.column_num, A.row_num, B.column_num, AT_Matrix, B_Matrix, C_Matrix.Matrix);
      break;
    
    case 2:
      Cal_Matrix(A.row_num, A.column_num, B.row_num, A_Matrix, BT_Matrix, C_Matrix.Matrix);
      break;
    
    case 3:
      Cal_Matrix(A.column_num, A.row_num, B.row_num, AT_Matrix, BT_Matrix, C_Matrix.Matrix);
      break;

    default:
      break;
  }
  Write_Output(output_name, C_Matrix);
  delete [] A_Matrix;
  delete [] B_Matrix;
  delete [] AT_Matrix;
  delete [] BT_Matrix;
  delete [] C_Matrix.Matrix;
  delete [] A.value;
  delete [] B.value;
  return 0;
}

void Read_File(const char filename[], Temp_Matrix *A, Temp_Matrix *B)
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

void Write_Output(const char Output_Name[], C_Matrix_Struct C_Matrix)
{
  FILE *Output_File = fopen(Output_Name, "w");
  for(int i = 0; i < C_Matrix.row_num; i++)
  {
    for(int j = 0; j < C_Matrix.column_num; j++)
    {
      fprintf(Output_File ,"%3d", C_Matrix.Matrix[i][j]);
    }
    fprintf(Output_File,";\n");
  }
}

int** To_Matrix(Temp_Matrix *temp)
{
  temp -> column_num /= temp -> row_num;
  int row_num = temp -> row_num;
  int column_num = temp -> column_num;
  int **Matrix = new int *[row_num];
  for(int i = 0; i < row_num; i++)
  {
    Matrix[i] = new int[column_num]{0};
  }
  for(int i = 0; i < row_num; i++)
  {
    for(int j = 0; j < column_num; j++)
    {
      Matrix[i][j] = temp -> value[i * column_num + j];
    }
  }
  return Matrix;
}

int** Generate_Transpose_Matrix(int row, int column, int **Matrix)
{
  int **T_Matrix = new int *[column];
  for(int i = 0; i < column; i++)
  {
    T_Matrix[i] = new int[row]{0};
  }
  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < column; j++)
    {
      T_Matrix[j][i] = Matrix[i][j];
    }
  }
  return T_Matrix;
}

int Matrix_Condition(int m, int n, int p, int q)
{
  if(n == p) {return 0;}
  else if(m == p) {return 1;}
  else if(n == q) {return 2;}
  else if(m == q) {return 3;}
  else {return -1;}
}

C_Matrix_Struct Generate_C(int condition, int m, int n, int p, int q)
{
  int row, column;

  switch(condition)
  {
    case 0:
      row = m;
      column = q;
      break;
  
    case 1:
      row = n;
      column = q;
      break;
    
    case 2:
      row = m;
      column = p;
      break;

    case 3:
      row = n;
      column = p;
      break;

    default:
      break;
  }
  int **Matrix = new int *[row];
  for(int i = 0; i < row; i++)
  {
    Matrix[i] = new int[column]{0};
  }

  C_Matrix_Struct C_Matrix;
  C_Matrix.Matrix = Matrix;
  C_Matrix.row_num = row;
  C_Matrix.column_num = column;

  return C_Matrix;
}

void Cal_Matrix(int A_row, int A_column, int B_column, int **A_Matrix, int **B_Matrix, int **C_Matrix)
{
  for(int i = 0; i < A_row; i++)
  {
    for(int j = 0; j < B_column; j++)
    {
      for(int k = 0; k < A_column; k++)
      {
        C_Matrix[i][j] += A_Matrix[i][k] * B_Matrix[k][j];
      }
    }
  }
}