#ifndef _READFILE_H_
#define _READFILE_H_

#define MAX_TASK 1000000

typedef struct _processor_queue
{
	char *pq = new char[MAX_TASK];
	char *ts = new char[MAX_TASK];
	int rear = 0, front = 0, top = -1;
} Processor_Queue;

typedef struct _return_data
{
	Processor_Queue *return_processor;
	int return_processor_num;
} Return_Data;


Return_Data read_file(const char []);
void write_output(const char[], int, Processor_Queue *);
void create_thread_queue(int);
int get_processor_id(char [], int);
char get_task_name(char [], int);
void assign(int, char, Processor_Queue *);
void exec(int, int, Processor_Queue *);

#endif