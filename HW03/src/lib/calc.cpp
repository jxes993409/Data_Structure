#include <stdio.h>
#include <iostream>
#include "calc.h"
#include "readfile.h"

void calc(int operation_id, int poly_1_pos, int poly_2_pos, Polynomial *poly)
{
  Polynomial *return_poly = new Polynomial;
  Polynomial *poly_1 = new Polynomial;
  Polynomial *poly_2 = new Polynomial;
  Polynomial *poly_head = new Polynomial;
  Polynomial *poly_1_head = new Polynomial;
  Polynomial *poly_2_head = new Polynomial;
  Polynomial *return_poly_head = new Polynomial;
  return_poly->next = NULL;
  poly_head = poly;
  poly = poly->next;
  return_poly_head = return_poly;
  int len_1 = poly->len, len_2 = poly->len, return_len = 0;
  for(int i = 0; i < poly_1_pos; i++)
  {
    len_1 = poly->len;
    for(int j = 0; j < len_1; j++)
    {
      poly = poly->next;
    }
  }
  poly_1 = copy(poly, poly->len);
  poly_1_head = poly_1;
  while(true)
  {
    if(poly_1->next != NULL) {poly_1 = poly_1->next;}
    else {break;}
  }
  poly_1->next = poly_1_head;
  poly_1 = poly_1->next;
  poly = poly_head;
  poly = poly->next;
  for(int i = 0; i < poly_2_pos; i++)
  {
    len_2 = poly->len;
    for(int j = 0; j < len_2; j++)
    {
      poly = poly->next;
    }
  }
  poly_2 = copy(poly, poly->len);
  poly_2_head = poly_2;
  while(true)
  {
    if(poly_2->next != NULL) {poly_2 = poly_2->next;}
    else {break;}
  }
  poly_2->next = poly_2_head;
  poly_2 = poly_2->next;
  poly = poly_head;
  
  if(operation_id == 1 || operation_id == 2)
  {
    len_1 = poly_1->len;
    len_2 = poly_2->len;
    for(int i = 0; i < len_1; i++)
    {
      for(int j = 0; j < len_2; j++)
      {
        if(poly_1->exp_x == poly_2->exp_x && poly_1->exp_y == poly_2->exp_y && poly_1->exp_z == poly_2->exp_z)
        {
          poly_1->be_calc = 1;
          poly_2->be_calc = 1;
          if((poly_1->coef + poly_2->coef) != 0 && operation_id == 1)
          {
            while(true)
            {
              if(return_poly->next == NULL)
              {
                return_len++;
                return_poly->next = new Polynomial;
                return_poly = return_poly->next;
                return_poly->coef = poly_1->coef + poly_2->coef;
                return_poly->exp_x = poly_1->exp_x;
                return_poly->exp_y = poly_1->exp_y;
                return_poly->exp_z = poly_1->exp_z;
                return_poly->next = NULL;
                break;
              }
              else
              {
                return_poly = return_poly->next;
              }
            }
          }
          if((poly_1->coef - poly_2->coef) != 0 && operation_id == 2)
          {
            while(true)
            {
              if(return_poly->next == NULL)
              {
                return_len++;
                return_poly->next = new Polynomial;
                return_poly = return_poly->next;
                return_poly->coef = poly_1->coef - poly_2->coef;
                return_poly->exp_x = poly_1->exp_x;
                return_poly->exp_y = poly_1->exp_y;
                return_poly->exp_z = poly_1->exp_z;
                return_poly->next = NULL;
                break;
              }
              else
              {
                return_poly = return_poly->next;
              }
            }
          }
        }
        poly_2 = poly_2->next;
      }
      poly_1 = poly_1->next;
    }
    poly_1 = poly_1->next;
    for(int i = 0; i < len_1; i++)
    {
      if(!poly_1->be_calc)
      {
        while(true)
        {
          if(return_poly->next == NULL)
          {
            return_len++;
            return_poly->next = new Polynomial;
            return_poly = return_poly->next;
            return_poly->coef = poly_1->coef;
            return_poly->exp_x = poly_1->exp_x;
            return_poly->exp_y = poly_1->exp_y;
            return_poly->exp_z = poly_1->exp_z;
            return_poly->next = NULL;
            break;
          }
          else
          {
            return_poly = return_poly->next;
          }
        }
      }
      poly_1 = poly_1->next;
    }
    poly_2 = poly_2->next;
    for(int i = 0; i < len_2; i++)
    {
      if(!poly_2->be_calc)
      {
        while(true)
        {
          if(return_poly->next == NULL)
          {
            return_len++;
            return_poly->next = new Polynomial;
            return_poly = return_poly->next;
            if(operation_id == 1) {return_poly->coef = poly_2->coef;}
            else {return_poly->coef = -poly_2->coef;}
            return_poly->exp_x = poly_2->exp_x;
            return_poly->exp_y = poly_2->exp_y;
            return_poly->exp_z = poly_2->exp_z;
            return_poly->next = NULL;
            break;
          }
          else
          {
            return_poly = return_poly->next;
          }
        }
      }
      poly_2 = poly_2->next;
    }
    return_poly->next = return_poly_head->next;
    return_poly = return_poly->next;
  }
  else if(operation_id == 3)
  {
    len_1 = poly_1->len;
    len_2 = poly_2->len;
    for(int i = 0; i < len_2; i++)
    {
      for(int j = 0; j < len_1; j++)
      {
        while(true)
        {
          if(return_poly->next == NULL)
          {
            return_len++;
            return_poly->next = new Polynomial;
            return_poly = return_poly->next;
            return_poly->coef = poly_1->coef * poly_2->coef;
            return_poly->exp_x = poly_1->exp_x + poly_2->exp_x;
            return_poly->exp_y = poly_1->exp_y + poly_2->exp_y;
            return_poly->exp_z = poly_1->exp_z + poly_2->exp_z;
            return_poly->next = NULL;
            break;
          }
          else
          {
            return_poly = return_poly->next;
          }
        }
        poly_1 = poly_1->next;
      }
      poly_2 = poly_2->next;
    }
    return_poly->next = return_poly_head->next;
    return_poly = return_poly->next;
    for(int i = 0; i < return_len; i++)
    {
      Polynomial *temp = new Polynomial;
      temp = return_poly->next;
      for(int j = i + 1; j < return_len; j++)
      {
        if(return_poly->exp_x == temp->exp_x && return_poly->exp_y == temp->exp_y && return_poly->exp_z == temp->exp_z)
        {
          return_poly->coef = return_poly->coef + temp->coef;
          temp->coef = 0;
        }
        temp = temp->next;
      }
      return_poly = return_poly->next;
    }
    int temp_len = return_len;
    for(int i = 0; i < temp_len; i++)
    {
      Polynomial *front = new Polynomial;
      front = return_poly;
      return_poly = return_poly->next;
      if(return_poly->coef == 0)
      {
        delete_node(front, return_poly);
        return_poly = front;
        return_len--;
      }
    }
  }
  else if(operation_id == 4)
  {
    Polynomial *front = new Polynomial;
    Polynomial *delete_start = new Polynomial;
    front = poly_head;
    poly = poly->next;
    for(int i = 0; i <= poly_1_pos; i++)
    {
      len_1 = poly->len;
      for(int j = 0; j < len_1; j++)
      {
        if((i + 1) == poly_1_pos && (j + 1) == len_1)
        {
          front = poly;
        }
        poly = poly->next;
      }
    }
    delete_start = front->next;
    for(int i = 0; i < len_1 - 1; i++)
    {
      delete delete_start;
      delete_start = delete_start->next;
    }
    if(poly_1_pos == 0) {poly_head->next = poly;}
    else {front->next = poly;}
  }
  if(operation_id != 4)
  {
    while(poly->next != NULL) {poly = poly->next;}
    if(return_len == 0)
    {
      poly->next = new Polynomial;
      poly = poly->next;
      poly->next = NULL;
    }
    else
    {
      for(int i = 0; i < return_len; i++)
      {
        return_poly->len = return_len;
        poly->next = return_poly;
        poly = poly->next;
        return_poly = return_poly->next;
      }
      poly->next = NULL;
    }
  }
  delete poly_1_head;
  delete poly_2_head;
  delete return_poly_head;
}

Polynomial* copy(Polynomial *poly, int count)
{
  if(poly == NULL || count == 0) {return NULL;}
  else
  {
    Polynomial *copy_poly = new Polynomial;
    copy_poly->coef = poly->coef;
    copy_poly->exp_x = poly->exp_x;
    copy_poly->exp_y = poly->exp_y;
    copy_poly->exp_z = poly->exp_z;
    copy_poly->len = poly->len;
    copy_poly->next = copy(poly->next, count - 1);
    return copy_poly;
  }
}

void delete_node(Polynomial *poly, Polynomial *del)
{
  poly->next = del->next;
  delete del;
  del = NULL;
}