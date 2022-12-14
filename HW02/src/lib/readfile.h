#ifndef _READFILE_H_
#define _READFILE_H_

#define MAX_TASK 1000000

typedef struct _processor_queue
{
	char *pq = new char[MAX_TASK];
	char *ts = new char[MAX_TASK];
	int rear = 0, front = 0, top = -1;
} Processor_Queue;

Processor_Queue* read_file(const char [], int *);
void write_output(const char[], int, Processor_Queue *);

#endif