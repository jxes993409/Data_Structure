#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "readfile.h"
#include "calc.h"

void read_file(const char filename[], Polynomial *poly)
{
  FILE *input_file = fopen(filename, "r");
  char *line = new char[50];
  int *num = new int[3]();
  int *coef_exp = new int[4]();

  while((fscanf(input_file, "%[^\n]%*c", line)) != EOF)
  {
    // Operation ID: 0
    if(line[0] == '0')
    {
      get_num(line, num, 0);
      // printf("0 %d\n", num[0]);
      for(int i = 0; i < num[0]; i++)
      {
        fscanf(input_file, "%[^\n]%*c", line);
        get_coef_exp(line, coef_exp);
        // printf("%d %d %d %d\n", coef_exp[0], coef_exp[1], coef_exp[2], coef_exp[3]);
        add_node(num[0], coef_exp, poly);
      }
    }
    // Operation ID: 1 (+)
    else if(line[0] == '1')
    {
      get_num(line, num, 1);
      // printf("1 %d %d\n", num[0], num[1]);
      calc(1, num[0], num[1], poly);
    }
    // Operation ID: 2 (-)
    else if(line[0] == '2')
    {
      get_num(line, num, 1);
      // printf("2 %d %d\n", num[0], num[1]);
      calc(2, num[0], num[1], poly);
    }
    // Operation ID: 3
    else if(line[0] == '3')
    {
      get_num(line, num, 1);
      // printf("3 %d %d\n", num[0], num[1]);
      calc(3, num[0], num[1], poly);
    }
    // Operation ID: 4
    else if(line[0] == '4')
    {
      // printf("count: %d\n", poly_count--);
      get_num(line, num, 0);
      // printf("4 %d\n", num[0]);
      calc(4, num[0], -1, poly);
    }
  }
  // free the memory and close the file
  delete [] line;
  delete [] num;
  delete [] coef_exp;
  fclose(input_file);
}

void write_output(const char filename[], Polynomial *poly)
{
  FILE *output_file = fopen(filename, "w");
  if(poly == NULL) printf("NULL\n");
  poly = poly->next;
  while(poly != NULL)
  {
    int len = poly->len;
    for(int i = 0; i < len; i++)
    {
      if(!i) fprintf(output_file, "%d\n", len);
      fprintf(output_file, "%d %d %d %d\n", poly->coef, poly->exp_x, poly->exp_y, poly->exp_z);
      poly = poly->next;
    } 
  }
  fclose(output_file);
}

void add_node(int len, int *coef_exp, Polynomial *poly)
{
  while(true)
	{
		if(poly->next == NULL)
		{
			poly->next = new Polynomial;
			poly = poly->next;
      poly->len = len;
			poly->coef = coef_exp[0];
      poly->exp_x = coef_exp[1];
      poly->exp_y = coef_exp[2];
      poly->exp_z = coef_exp[3];
			poly->next = NULL;
			break;
		}
    else
		{
			poly= poly->next;
		}
	}
}

void get_num(const char line[], int *num, int state)
{
  int i = 2;
  char num_char[10];
  // Operation ID: 0
  if(!state)
  {
    memset(num_char, 0, size_t(10));
    for(; i < int(strlen(line)); i++)
    {
      if(isdigit(line[i]))
      {
        num_char[i - 2] = line[i];
      }
    }
    num[0] = atoi(num_char);
  }
  // Operation ID: 1, 2, 3, 4
  else
  {
    for(int j = 0; j < 2; j++)
    {
      int count = 0;
      memset(num_char, 0, size_t(10));
      for(; i < int(strlen(line)); i++)
      {
        if(isdigit(line[i]))
        {
          num_char[count++] = line[i];
        }
        if(line[i] == ' ')
        {
          i++;
          break;
        }
        num[j] = atoi(num_char);
      }
    }
  }
}

void get_coef_exp(const char line[], int *coef_exp)
{
  int i = 0;
  char coef_exp_char[10];
  for(int j = 0; j < 4; j++)
  {
    int count = 0;
    memset(coef_exp_char, 0, size_t(10));
    for(; i < int(strlen(line)); i++)
    {
      if(line[i] == '-')
      {
        coef_exp_char[count++] = line[i];
      }
      if(isdigit(line[i]))
      {
        coef_exp_char[count++] = line[i];
      }
      if(line[i] == ' ')
      {
        i++;
        break;
      }
      coef_exp[j] = atoi(coef_exp_char);
    }
  }
}