#include <stdio.h>
#include <stdlib.h>
#include "readfile.h"

void assign(int processor_id, char task_name, Processor_Queue *processor)
{
  int *front;
  front = &processor[processor_id].front;
  // queue_is_full();
  if(*front > MAX_TASK)
  {
    fprintf(stderr,"Too Many Task!\n");
    exit(EXIT_FAILURE);
  }
  // push();
  processor[processor_id].pq[*front] = task_name;
  *front = *front + 1;
}

void exec(int processor_id, int processor_num, Processor_Queue *processor)
{
  int *rear, *front, *top;
  int max_queue = 0, max_queue_index = -1;
  rear = &processor[processor_id].rear;
  front = &processor[processor_id].front;
  top = &processor[processor_id].top;
  // queue_is_empty();
  if(*rear == *front)
  {
    // rule step 1 and 2, find the smallest pocessor ID(2) which has maximum number of queueing tasks(1)
    for(int i = processor_num - 1; i >= 0; i--)
    {
      if((processor[i].front - processor[i].rear) >= max_queue)
      {
        max_queue = processor[i].front - processor[i].rear;
        max_queue_index = i;
      }
    }
    // rule step 3
    *top = *top + 1;
    processor[processor_id].ts[*top] = processor[max_queue_index].pq[--processor[max_queue_index].front];
  }
  // pop();
  else
  {
    *top = *top + 1;
    processor[processor_id].ts[*top] = processor[processor_id].pq[*rear];
    *rear = *rear + 1;
  }
}