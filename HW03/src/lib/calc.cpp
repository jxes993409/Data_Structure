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
  Polytable poly_table_head;
  int len_1 = 0, len_2 = 0, return_len = 0;

  if(operation_id != 4)
  {
    return_poly_head = return_poly;
    poly_table_head = *poly_table;

    for(int i = 0; i < poly_1_pos; i++)
    {
      poly_table = poly_table->next;
      poly_table = poly_table->next;
    }
    poly = poly_table->address; // poly_1 head
    poly_1 = copy(poly, poly->value.len);
    poly_1_head = poly_1;

    poly_table = &poly_table_head;
    for(int i = 0; i < poly_2_pos; i++)
    {
      poly_table = poly_table->next;
      poly_table = poly_table->next;
    }
    poly = poly_table->address; // poly_2 head
    poly_2 = copy(poly, poly->value.len);
    poly_2_head = poly_2;
  }

  if(operation_id == 1 || operation_id == 2)
  {
    len_1 = poly_1->value.len;
    len_2 = poly_2->value.len;
    for(int i = 0; i < len_1; i++)
    {
      for(int j = 0; j < len_2; j++)
      {
        return_poly = return_poly_head;
        if(poly_1->value.exp_x == poly_2->value.exp_x && poly_1->value.exp_y == poly_2->value.exp_y && poly_1->value.exp_z == poly_2->value.exp_z)
        {
          poly_1->value.be_calc = 1;
          poly_2->value.be_calc = 1;
          if((poly_1->value.coef + poly_2->value.coef) != 0 && operation_id == 1)
          {
            return_poly = return_poly_head;
            if(return_poly->next == NULL)
            {
              return_len++;
              return_poly->next = create_node(0, poly_1->value.coef + poly_2->value.coef, poly_1->value.exp_x, poly_1->value.exp_y, poly_1->value.exp_z);
            }
            else
            {
              Listnode *previous_node = new Listnode;
              Listnode *temp = new Listnode;
              int flag = 0;
              previous_node = return_poly_head;
              temp = create_node(0, poly_1->value.coef + poly_2->value.coef, poly_1->value.exp_x, poly_1->value.exp_y, poly_1->value.exp_z);
              return_poly = return_poly->next;
              while(return_poly != NULL)
              {
                if(return_poly->value.exp_x < temp->value.exp_x)
                {
                  flag = 1;
                  return_len++;
                  insert_node(previous_node, return_poly, temp);
                  break;
                }
                else if(return_poly->value.exp_x > temp->value.exp_x)
                {
                  previous_node = return_poly;
                  return_poly = return_poly->next;
                }
                else if(return_poly->value.exp_x == temp->value.exp_x)
                {
                  if(return_poly->value.exp_y < temp->value.exp_y)
                  {
                    flag = 1;
                    return_len++;
                    insert_node(previous_node, return_poly, temp);
                    break;
                  }
                  else if(return_poly->value.exp_y > temp->value.exp_y)
                  {
                    previous_node = return_poly;
                    return_poly = return_poly->next;
                  }
                  else if(return_poly->value.exp_y == temp->value.exp_y)
                  {
                    if(return_poly->value.exp_z < temp->value.exp_z)
                    {
                      flag = 1;
                      return_len++;
                      insert_node(previous_node, return_poly, temp);
                      break;
                    }
                    else if(return_poly->value.exp_z > temp->value.exp_z)
                    {
                      previous_node = return_poly;
                      return_poly = return_poly->next;
                    }
                  }
                }
              }
              // printf("%p\n", return_poly);
              if(!flag)
              {
                return_len++;
                previous_node->next = temp;
              }
              temp = NULL;
              previous_node = NULL;
              delete temp;
              delete previous_node;
            }
            poly_2 = poly_2_head;
            break;
          }
          if((poly_1->value.coef - poly_2->value.coef) != 0 && operation_id == 2)
          {
            return_poly = return_poly_head;
            if(return_poly->next == NULL)
            {
              return_len++;
              return_poly->next = create_node(0, poly_1->value.coef - poly_2->value.coef, poly_1->value.exp_x, poly_1->value.exp_y, poly_1->value.exp_z);
            }
            else
            {
              Listnode *previous_node = new Listnode;
              Listnode *temp = new Listnode;
              int flag = 0;
              previous_node = return_poly_head;
              temp = create_node(0, poly_1->value.coef - poly_2->value.coef, poly_1->value.exp_x, poly_1->value.exp_y, poly_1->value.exp_z);
              return_poly = return_poly->next;
              while(return_poly != NULL)
              {
                if(return_poly->value.exp_x < temp->value.exp_x)
                {
                  flag = 1;
                  return_len++;
                  insert_node(previous_node, return_poly, temp);
                  break;
                }
                else if(return_poly->value.exp_x > temp->value.exp_x)
                {
                  previous_node = return_poly;
                  return_poly = return_poly->next;
                }
                else if(return_poly->value.exp_x == temp->value.exp_x)
                {
                  if(return_poly->value.exp_y < temp->value.exp_y)
                  {
                    flag = 1;
                    return_len++;
                    insert_node(previous_node, return_poly, temp);
                    break;
                  }
                  else if(return_poly->value.exp_y > temp->value.exp_y)
                  {
                    previous_node = return_poly;
                    return_poly = return_poly->next;
                  }
                  else if(return_poly->value.exp_y == temp->value.exp_y)
                  {
                    if(return_poly->value.exp_z < temp->value.exp_z)
                    {
                      flag = 1;
                      return_len++;
                      insert_node(previous_node, return_poly, temp);
                      break;
                    }
                    else if(return_poly->value.exp_z > temp->value.exp_z)
                    {
                      previous_node = return_poly;
                      return_poly = return_poly->next;
                    }
                  }
                }
              }
              // printf("%p\n", return_poly);
              if(!flag)
              {
                return_len++;
                previous_node->next = temp;
              }
              temp = NULL;
              previous_node = NULL;
              delete temp;
              delete previous_node;
            }
            poly_2 = poly_2_head;
            // printf("break!\n");
            break;
          }
        }
        if(poly_2->next != NULL) {poly_2 = poly_2->next;}
        else {poly_2 = poly_2_head;}
      }
      if(poly_1->next != NULL) {poly_1 = poly_1->next;}
      else {poly_1 = poly_1_head;}
    }

    // append remaining terms
    poly_1 = poly_1_head;
    for(int i = 0; i < len_1; i++)
    {
      if(!poly_1->value.be_calc)
      {
        return_poly = return_poly_head;
        if(return_poly->next == NULL)
        {
          return_len++;
          return_poly->next = create_node(0, poly_1->value.coef, poly_1->value.exp_x, poly_1->value.exp_y, poly_1->value.exp_z);
        }
        else
        {
          Listnode *previous_node = new Listnode;
          Listnode *temp = new Listnode;
          int flag = 0;
          previous_node = return_poly_head;
          temp = create_node(0, poly_1->value.coef, poly_1->value.exp_x, poly_1->value.exp_y, poly_1->value.exp_z);
          return_poly = return_poly->next;
          while(return_poly != NULL)
          {
            if(return_poly->value.exp_x < temp->value.exp_x)
            {
              flag = 1;
              return_len++;
              insert_node(previous_node, return_poly, temp);
              break;
            }
            else if(return_poly->value.exp_x > temp->value.exp_x)
            {
              previous_node = return_poly;
              return_poly = return_poly->next;
            }
            else if(return_poly->value.exp_x == temp->value.exp_x)
            {
              if(return_poly->value.exp_y < temp->value.exp_y)
              {
                flag = 1;
                return_len++;
                insert_node(previous_node, return_poly, temp);
                break;
              }
              else if(return_poly->value.exp_y > temp->value.exp_y)
              {
                previous_node = return_poly;
                return_poly = return_poly->next;
              }
              else if(return_poly->value.exp_y == temp->value.exp_y)
              {
                if(return_poly->value.exp_z < temp->value.exp_z)
                {
                  flag = 1;
                  return_len++;
                  insert_node(previous_node, return_poly, temp);
                  break;
                }
                else if(return_poly->value.exp_z > temp->value.exp_z)
                {
                  previous_node = return_poly;
                  return_poly = return_poly->next;
                }
              }
            }
          }
          // printf("%p\n", return_poly);
          if(!flag)
          {
            return_len++;
            previous_node->next = temp;
          }
          temp = NULL;
          previous_node = NULL;
          delete temp;
          delete previous_node;
        }
      }
      if(poly_1->next != NULL) {poly_1 = poly_1->next;}
      else {poly_1 = poly_1_head;}
    }
    poly_2 = poly_2_head;
    for(int i = 0; i < len_2; i++)
    {
      if(!poly_2->value.be_calc)
      {
        return_poly = return_poly_head;
        if(return_poly->next == NULL)
        {
          return_len++;
          if(operation_id == 1) {return_poly->next = create_node(0, poly_2->value.coef, poly_2->value.exp_x, poly_2->value.exp_y, poly_2->value.exp_z);}
          else {return_poly->next = create_node(0, -poly_2->value.coef, poly_2->value.exp_x, poly_2->value.exp_y, poly_2->value.exp_z);}
        }
        else
        {
          Listnode *previous_node = new Listnode;
          Listnode *temp = new Listnode;
          int flag = 0;
          previous_node = return_poly_head;
          if(operation_id == 1) {temp = create_node(0, poly_2->value.coef, poly_2->value.exp_x, poly_2->value.exp_y, poly_2->value.exp_z);}
          else {temp = create_node(0, -poly_2->value.coef, poly_2->value.exp_x, poly_2->value.exp_y, poly_2->value.exp_z);}
          return_poly = return_poly->next;
          while(return_poly != NULL)
          {
            if(return_poly->value.exp_x < temp->value.exp_x)
            {
              flag = 1;
              return_len++;
              insert_node(previous_node, return_poly, temp);
              break;
            }
            else if(return_poly->value.exp_x > temp->value.exp_x)
            {
              previous_node = return_poly;
              return_poly = return_poly->next;
            }
            else if(return_poly->value.exp_x == temp->value.exp_x)
            {
              if(return_poly->value.exp_y < temp->value.exp_y)
              {
                flag = 1;
                return_len++;
                insert_node(previous_node, return_poly, temp);
                break;
              }
              else if(return_poly->value.exp_y > temp->value.exp_y)
              {
                previous_node = return_poly;
                return_poly = return_poly->next;
              }
              else if(return_poly->value.exp_y == temp->value.exp_y)
              {
                if(return_poly->value.exp_z < temp->value.exp_z)
                {
                  flag = 1;
                  return_len++;
                  insert_node(previous_node, return_poly, temp);
                  break;
                }
                else if(return_poly->value.exp_z > temp->value.exp_z)
                {
                  previous_node = return_poly;
                  return_poly = return_poly->next;
                }
              }
            }
          }
          // printf("%p\n", return_poly);
          if(!flag)
          {
            return_len++;
            previous_node->next = temp;
          }
          temp = NULL;
          previous_node = NULL;
          delete temp;
          delete previous_node;
        }
      }
      if(poly_2->next != NULL) {poly_2 = poly_2->next;}
      else {poly_2 = poly_2_head;}
    }
  }
  else if(operation_id == 3)
  {
    len_1 = poly_1->value.len;
    len_2 = poly_2->value.len;
    return_len = 0;
    for(int i = 0; i < len_2; i++)
    {
      for(int j = 0; j < len_1; j++)
      {
        return_poly = return_poly_head;
        if(return_poly->next == NULL)
        {
          return_len++;
          return_poly->next = create_node(0, poly_1->value.coef * poly_2->value.coef, poly_1->value.exp_x + poly_2->value.exp_x, poly_1->value.exp_y + poly_2->value.exp_y, poly_1->value.exp_z + poly_2->value.exp_z);
        }
        else
        {
          Listnode *previous_node = new Listnode;
          Listnode *temp = new Listnode;
          int flag = 0;
          previous_node = return_poly_head;
          temp = create_node(0, poly_1->value.coef * poly_2->value.coef, poly_1->value.exp_x + poly_2->value.exp_x, poly_1->value.exp_y + poly_2->value.exp_y, poly_1->value.exp_z + poly_2->value.exp_z);
          return_poly = return_poly->next;
          while(return_poly != NULL)
          {
            if(return_poly->value.exp_x < temp->value.exp_x)
            {
              flag = 1;
              return_len++;
              insert_node(previous_node, return_poly, temp);
              break;
            }
            else if(return_poly->value.exp_x > temp->value.exp_x)
            {
              previous_node = return_poly;
              return_poly = return_poly->next;
            }
            else if(return_poly->value.exp_x == temp->value.exp_x)
            {
              if(return_poly->value.exp_y < temp->value.exp_y)
              {
                flag = 1;
                return_len++;
                insert_node(previous_node, return_poly, temp);
                break;
              }
              else if(return_poly->value.exp_y > temp->value.exp_y)
              {
                previous_node = return_poly;
                return_poly = return_poly->next;
              }
              else if(return_poly->value.exp_y == temp->value.exp_y)
              {
                if(return_poly->value.exp_z < temp->value.exp_z)
                {
                  flag = 1;
                  return_len++;
                  insert_node(previous_node, return_poly, temp);
                  break;
                }
                else if(return_poly->value.exp_z > temp->value.exp_z)
                {
                  previous_node = return_poly;
                  return_poly = return_poly->next;
                }
                else if(return_poly->value.exp_z == temp->value.exp_z)
                {
                  flag = 1;
                  if((return_poly->value.coef + temp->value.coef) != 0) {return_poly->value.coef += temp->value.coef;}
                  else
                  {
                    return_len--;
                    if(return_poly->next == NULL) {delete return_poly;}
                    else {delete_node(return_poly->next, return_poly);}
                  }
                  break;
                }
              }
            }
          }
          // printf("%p\n", return_poly);
          if(!flag)
          {
            return_len++;
            previous_node->next = temp;
          }
          temp = NULL;
          previous_node = NULL;
          delete temp;
          delete previous_node;
        }
        if(poly_1->next != NULL) {poly_1 = poly_1->next;}
        else {poly_1 = poly_1_head;}
      }
      if(poly_2->next != NULL) {{poly_2 = poly_2->next;}}
      else {poly_2 = poly_2_head;}
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
    else // delete the last polynomial
    {
      Polytable *delete_table_start = new Polytable;
      delete_table_start = poly_table->next; // delete polymial head
      poly_table->next = NULL;
      delete_start = poly->next; // delete polymial head
      poly_address->tail = poly; // change the polynomial tail
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
    if(return_len) {return_poly = return_poly_head->next;}
    if(return_len == 1 || return_len == 0)
    {
      print_node(return_poly, 1);
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
  // free the memory
  return_poly = return_poly_head;
  for(int i = 0; i < len_1; i++) {if(poly_1->next != NULL) {delete_node(poly_1->next, poly_1);}}
  for(int i = 0; i < len_2; i++) {if(poly_2->next != NULL) {delete_node(poly_2->next, poly_2);}}
  for(int i = 0; i < return_len; i++) {if(return_poly->next != NULL) {delete_node(return_poly->next, return_poly);}}
  delete return_poly;
  delete poly_1;
  delete poly_2;
  poly_1_head = NULL;
  poly_2_head = NULL;
  return_poly_head = NULL;
  delete poly_1_head;
  delete poly_2_head;
  delete return_poly_head;
  
}

void print_node(Listnode *poly, int i)
{
  if(!i) {printf("%d %d %d %d\n", poly->value.coef, poly->value.exp_x, poly->value.exp_y, poly->value.exp_z);}
  else
  {
    while(poly != NULL)
    {
      printf("%d %d %d %d\n", poly->value.coef, poly->value.exp_x, poly->value.exp_y, poly->value.exp_z);
      poly = poly->next;
    }
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
  // move the next node value to the delete one
  // delete the next node
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
  // move the next node value to the delete one
  // delete the next node
  del->address = del_next->address;
  del->next = del_next->next;
  del_next->address = NULL;
  delete del_next;
}

void insert_node(Listnode *poly, Listnode *poly_next, Listnode *newnode)
{
  // poly->next = NULL;
  poly->next = newnode;
  newnode->next = poly_next;
}