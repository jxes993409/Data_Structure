#ifndef _READFILE_H_
#define _READFILE_H_

typedef struct _thread_queue
{
	char tq[10];
} Thread_Queue;

void read_file(const char filename[]);
int get_processor_id(char [], int);
char get_task_name(char [], int);

#endif