#include <stdio.h> 
#include <stdbool.h>
#define MAX 4
typedef char queueElement ;

typedef struct queue
{
	int count ;
	int head ;
	int tail ;
	queueElement element[MAX];

}Queue;

void initQueue(Queue * q);
bool queuefull(Queue * q);
bool queueempty(Queue * q);
void append(Queue * q , int c);
void serve(Queue * q , int * x);
int queuesize(Queue * q);
int main()
{
		Queue  q;
		initQueue(&q);
		int input ;
		int element ;
		printf("count %d\n",q.count);
		while(true)
		{
			printf("Enter you options\n\t0.INSERT\n\t1.DELETE\n\t2.DISPLY\n\t3.QueueSize\n\t4.EXIT\n");
			scanf("%d",&input);
			switch(input)
			{
				case 0 : printf("enter you element to insert :\n");
						 scanf("%d",&element);
						 append(&q,element);
						 break ;
				case 1 : serve(&q,&element);
						printf("deleted element %d\n",element);
						 break ;
				case 2 :printf("elements in the Queue \n");
						break ;
				case 3 :printf("Size of Queue is %d\n",queuesize(&q));
						break ;
				case 4:printf("good bye \n");
						return 0 ;
						break ;
				default:printf("Enter valid options between 1-4 only \n");
			}
		}

}

void append(Queue * q , int c)
{
		if(queuefull(q))
			printf("Queue is full \n");
		else
		{
			q->tail = ( q->tail + 1 ) % MAX ;

			q->element[q->tail] = c;
			q->count++ ;

		}
}

void serve(Queue * q , int * x)
{
		if(queueempty(q))
			printf("Error : Queue is empty \n");
		else
		{
			*x = q->element[q->head];
			q->head = (q->head + 1) % MAX ;
			q->count-- ;

		}

}

void initQueue(Queue * q)
{
		q->count = 0 ;
		q->head = 1 ;
		q->tail =  0 ;

}

bool queuefull(Queue * q)
{

	if(q->count >= MAX)	
		return true ;
	else 
		return false ;
}

bool queueempty(Queue * q)
{
	if(q->count == 0)
		return true ;
	else 
		return false ;
}

int queuesize(Queue * q)
{

	return q->count ;	
}












