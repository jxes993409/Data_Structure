#include <stdio.h>
#include <iostream>
#include "readfile.h"
#include "calc.h"

void calc(int operation_id, int poly_1_pos, int poly_2_pos, Listnode *poly, Polyaddress *poly_address, Polytable *poly_table)
{
  Listnode *return_poly = new Listnode;
  Listnode *poly_1 = new Listnode;
  Listnode *poly_2 = new Listnode;
  Listnode *poly_1_head = new Listnode;
  Listnode *poly_2_head = new Listnode;
  Listnode *return_poly_head = new Listnode;
  Polytable *poly_table_head = new Polytable;

  return_poly_head = return_poly;
  poly_table_head = poly_table;
  int len_1 = 0, len_2 = 0, return_len = 0;

  for(int i = 0; i < poly_1_pos; i++)
  {
    poly_table = poly_table->next;
    poly_table = poly_table->next;
  }
  poly = poly_table->address;
  poly_1 = copy(poly, poly->value.len);
  poly_1_head = poly_1;

  poly_table = poly_table_head;
  for(int i = 0; i < poly_2_pos; i++)
  {
    poly_table = poly_table->next;
    poly_table = poly_table->next;
  }
  poly = poly_table->address;
  poly_2 = copy(poly, poly->value.len);
  poly_2_head = poly_2;
  // if()
  if(operation_id == 1 || operation_id == 2)
  {
    len_1 = poly_1->value.len;
    len_2 = poly_2->value.len;
    for(int i = 0; i < len_1; i++)
    {
      for(int j = 0; j < len_2; j++)
      {
        if(poly_1->value.exp_x == poly_2->value.exp_x && poly_1->value.exp_y == poly_2->value.exp_y && poly_1->value.exp_z == poly_2->value.exp_z)
        {
          poly_1->value.be_calc = 1;
          poly_2->value.be_calc = 1;
          if((poly_1->value.coef + poly_2->value.coef) != 0 && operation_id == 1)
          {
            return_len++;
            return_poly->next = create_node(0, poly_1->value.coef + poly_2->value.coef, poly_1->value.exp_x, poly_1->value.exp_y, poly_1->value.exp_z);
            return_poly = return_poly->next;
          }
          if((poly_1->value.coef - poly_2->value.coef) != 0 && operation_id == 2)
          {
            return_len++;
            return_poly->next = create_node(0, poly_1->value.coef - poly_2->value.coef, poly_1->value.exp_x, poly_1->value.exp_y, poly_1->value.exp_z);
            return_poly = return_poly->next;
          }
        }
        if(poly_2->next != NULL) poly_2 = poly_2->next;
        else {poly_2 = poly_2_head;}
      }
      if(poly_1->next != NULL) poly_1 = poly_1->next;
      else {poly_1 = poly_1_head;}
    }
    for(int i = 0; i < len_1; i++)
    {
      if(!poly_1->value.be_calc)
      {
        return_len++;
        return_poly->next = create_node(0, poly_1->value.coef, poly_1->value.exp_x, poly_1->value.exp_y, poly_1->value.exp_z);
        return_poly = return_poly->next;
      }
      if(poly_1->next != NULL) poly_1 = poly_1->next;
      else {poly_1 = poly_1_head;}
    }
    for(int i = 0; i < len_2; i++)
    {
      if(!poly_2->value.be_calc)
      {
        return_len++;
        if(operation_id == 1) {return_poly->next = create_node(0, poly_2->value.coef, poly_2->value.exp_x, poly_2->value.exp_y, poly_2->value.exp_z);}
        else {return_poly->next = create_node(0, -poly_2->value.coef, poly_2->value.exp_x, poly_2->value.exp_y, poly_2->value.exp_z);}
        return_poly = return_poly->next;
      }
      if(poly_2->next != NULL) poly_2 = poly_2->next;
      else {poly_2 = poly_2_head;}
    }
  }
  else if(operation_id == 3)
  {
    
    len_1 = poly_1->value.len;
    len_2 = poly_2->value.len;
    int temp_len = len_1 * len_2;
    printf("%d\n" ,temp_len);
    return_len = temp_len;
    // printf("%d %d\n", len_1, len_2);
    for(int i = 0; i < len_2; i++)
    {
      for(int j = 0; j < len_1; j++)
      {
        return_poly->next = create_node(0, poly_1->value.coef * poly_2->value.coef, poly_1->value.exp_x + poly_2->value.exp_x, poly_1->value.exp_y + poly_2->value.exp_y, poly_1->value.exp_z + poly_2->value.exp_z);
        return_poly = return_poly->next;
        if(poly_1->next != NULL) poly_1 = poly_1->next;
        else {poly_1 = poly_1_head;}
      }
      if(poly_2->next != NULL) poly_2 = poly_2->next;
      else {poly_2 = poly_2_head;}
    }
    return_poly = return_poly_head->next;
    for(int i = 0; i < return_len; i++)
    {
      Listnode *temp = new Listnode;
      temp = return_poly->next;
      for(int j = i + 1; j < return_len; j++)
      {
        if(return_poly->value.exp_x == temp->value.exp_x && return_poly->value.exp_y == temp->value.exp_y && return_poly->value.exp_z == temp->value.exp_z)
        {
          return_poly->value.coef = return_poly->value.coef + temp->value.coef;
          temp->value.coef = 0;
          temp->value.exp_x = 0;
          temp->value.exp_y = 0;
          temp->value.exp_z = 0;
        }
        temp = temp->next;
      }
      return_poly = return_poly->next;
      temp = NULL;
      delete temp;
    }
    return_poly = return_poly_head->next;
    for(int i = 0; i < temp_len; i++)
    {
      if(return_poly->next != NULL) {return_poly = return_poly->next;}
      else {return_poly = return_poly;}
      while(return_poly->value.coef == 0 && return_poly->next != NULL)
      {
        delete_node(return_poly->next, return_poly);
        return_len--;
      }
    }
  }
  else if(operation_id == 4)
  {
    Listnode *delete_start = new Listnode;
    for(int i = 0; i < poly_1_pos; i++)
    {
      poly_table = poly_table->next;
      poly_table = poly_table->next;
    }
    
    poly = poly_table->address; // previos polynomial tail
    if(poly_table->next->next->next != NULL) // delete polynomial next head != NULL
    {
      poly_table = poly_table->next; // delete polynomial head
      poly->next = poly_table->next->next->address; // delete polynomial next head
      delete_start = poly_table->address;
      len_1 = poly_table->address->value.len;
      for(int i = 0; i < 2; i++) {delete_poly_table_node(poly_table->next, poly_table);}
      for(int i = 1; i < len_1; i++) {delete_node(delete_start->next, delete_start);}
    }
    else
    {
      Polytable *delete_table_start = new Polytable;
      delete_table_start = poly_table->next;
      poly_table->next = NULL;
      delete_start = poly->next;
      poly_address->tail = poly;
      poly->next = NULL;
      len_1 = delete_start->value.len;
      delete_poly_table_node(delete_table_start->next, delete_table_start);
      for(int i = 1; i < len_1; i++) {delete_node(delete_start->next, delete_start);}
      
      delete_table_start->next = NULL;
      delete delete_table_start;
      delete_table_start = NULL;
    }
    delete_start->next = NULL;
    delete delete_start;
    delete_start = NULL;
  }
  if(operation_id != 4)
  {

    if(return_len == 1 || return_len == 0)
    {
      if(return_poly->value.coef == 0) {add_node(1, 0, 0, 0, 0, poly, poly_address);}
      else {add_node(1, return_poly->value.coef, return_poly->value.exp_x, return_poly->value.exp_y, return_poly->value.exp_z, poly, poly_address);}
      for(int i = 0; i < 2; i++)
      {
        while(poly_table->next != NULL) {poly_table = poly_table->next;}
        poly_table->next = add_poly_table_node(poly_address->tail);
      }
    }
    else
    {
      return_poly = return_poly_head->next;
      bubble_sort(return_poly, return_len, 0);
      bubble_sort(return_poly, return_len, 1);
      bubble_sort(return_poly, return_len, 2);
      for(int i = 0; i < return_len; i++)
      {
        add_node(return_len, return_poly->value.coef, return_poly->value.exp_x, return_poly->value.exp_y, return_poly->value.exp_z, poly, poly_address);
        return_poly = return_poly->next;
        if(!i)
        {
          while(poly_table->next != NULL) {poly_table = poly_table->next;}
          poly_table->next = add_poly_table_node(poly_address->tail);
        }
      }
      while(poly_table->next != NULL) {poly_table = poly_table->next;}
      poly_table->next = add_poly_table_node(poly_address->tail);
    }
  }
  return_poly = return_poly_head->next;
  for(int i = 0; i < len_1; i++) {if(poly_1->next != NULL) {delete_node(poly_1->next, poly_1);}}
  for(int i = 0; i < len_2; i++) {if(poly_2->next != NULL) {delete_node(poly_2->next, poly_2);}}
  for(int i = 0; i < return_len; i++) {if(return_poly->next != NULL) {delete_node(return_poly->next, return_poly);}}
  delete return_poly;
  delete poly_1;
  delete poly_2;
  poly_1_head = NULL;
  poly_2_head = NULL;
  return_poly_head = NULL;
  poly_table_head = NULL;
  delete poly_1_head;
  delete poly_2_head;
  delete return_poly_head;
  delete poly_table_head;
}

void print_node(Listnode *poly)
{
  while(poly != NULL)
  {
    printf("%d %d %d %d\n", poly->value.coef, poly->value.exp_x, poly->value.exp_y, poly->value.exp_z);
    poly = poly->next;
  }
}

void swap_coef_exp(Listnode *x, Listnode *y)
{
  // printf("before\n%d %d %d %d\n", x->value.coef, x->value.exp_x, x->value.exp_y, x->value.exp_z);
  // printf("%d %d %d %d\n", y->value.coef, y->value.exp_x, y->value.exp_y, y->value.exp_z);
  Listnode temp;
  // temp = x
  temp.value.coef = x->value.coef;
  temp.value.exp_x = x->value.exp_x;
  temp.value.exp_y = x->value.exp_y;
  temp.value.exp_z = x->value.exp_z;
  // x = y
  x->value.coef = y->value.coef;
  x->value.exp_x = y->value.exp_x;
  x->value.exp_y = y->value.exp_y;
  x->value.exp_z = y->value.exp_z;
  // y = x
  y->value.coef = temp.value.coef;
  y->value.exp_x = temp.value.exp_x;
  y->value.exp_y = temp.value.exp_y;
  y->value.exp_z = temp.value.exp_z;
  // printf("after\n%d %d %d %d\n", x->value.coef, x->value.exp_x, x->value.exp_y, x->value.exp_z);
  // printf("%d %d %d %d\n", y->value.coef, y->value.exp_x, y->value.exp_y, y->value.exp_z);
}

void bubble_sort(Listnode *poly, int len, int count)
{
  // Listnode *copy_poly = new Listnode;
  // Listnode *head = new Listnode;
  // copy_poly = copy(poly, len);
  // head = poly;
  for(int i = 0; i < len; i++)
  {
    Listnode *temp = new Listnode;
    temp = poly->next;
    for(int j = i + 1; j < len; j++)
    {
      switch(count)
      {
        case 0:
          if(poly->value.exp_x <= temp->value.exp_x) {swap_coef_exp(poly, temp);}
          break;
        case 1:
          if(poly->value.exp_x == temp->value.exp_x)
          {
            if(poly->value.exp_y <= temp->value.exp_y) {swap_coef_exp(poly, temp);}
          }
          break;
        case 2:
          if(poly->value.exp_x == temp->value.exp_x)
          {
            if(poly->value.exp_y == temp->value.exp_y)
            {
              if(poly->value.exp_z < temp->value.exp_z) {swap_coef_exp(poly, temp);}
            }
          }
          break;
      }
      temp = temp->next;
    }
    poly = poly->next;
    temp = NULL;
    delete temp;
  }
}

void add_node(int len, int coef, int exp_x, int exp_y, int exp_z, Listnode *poly, Polyaddress *poly_address)
{
  poly = poly_address->tail;
  poly->next = create_node(len, coef, exp_x, exp_y, exp_z);
  poly_address->tail = poly->next;
}

Listnode *create_node(int len, int coef, int exp_x, int exp_y, int exp_z)
{
  Listnode *new_node = new Listnode;
  new_node->value.len = len;
  new_node->value.coef = coef;
  new_node->value.exp_x = exp_x;
  new_node->value.exp_y = exp_y;
  new_node->value.exp_z = exp_z;
  return new_node;
}

Polytable *add_poly_table_node(Listnode *poly)
{
  Polytable *new_node = new Polytable;
  new_node->address = poly;
  return new_node;
}

Listnode* copy(Listnode *poly, int count)
{
  if(poly == NULL || count == 0) {return NULL;}
  else
  {
    Listnode *copy_poly = new Listnode;
    copy_poly = create_node(poly->value.len, poly->value.coef, poly->value.exp_x, poly->value.exp_y, poly->value.exp_z);
    copy_poly->next = copy(poly->next, count - 1);
    return copy_poly;
  }
}

void delete_node(Listnode *del_next, Listnode *del)
{
  del->value.coef = del_next->value.coef;
  del->value.exp_x = del_next->value.exp_x;
  del->value.exp_y = del_next->value.exp_y;
  del->value.exp_z = del_next->value.exp_z;
  del->next = del_next->next;
  delete del_next;
  del_next = NULL;
}

void delete_poly_table_node(Polytable *del_next, Polytable *del)
{
  del->address = del_next->address;
  del->next = del_next->next;
  del_next->address = NULL;
  delete del_next;
}