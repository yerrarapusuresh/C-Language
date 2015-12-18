#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char QueueEntry ;

typedef struct queuenode
{
	QueueEntry info ;
	struct queuenode * next  ;
}QueueNode ;

typedef struct queue
{
	QueueNode * front ;
	QueueNode * rear ;
}Queue ;

QueueNode * newQueueNode (QueueEntry e)
{
	QueueNode * newNode = malloc(sizeof(QueueNode));
	newNode ->info = e ;
	newNode->next = NULL ;
	return newNode ;
}

void createQueue(Queue * q)
{
	q->front = q->rear = NULL ;

}
bool queueEmpty(Queue *q)
{
	if(q->front == NULL)
		return true ;
	else
		return false ;
}
void append(Queue * q , QueueNode * n)
{
	if(!n)
	{
		printf("Trying to insert empty node .\nOperation abort\n");

	}
	else if(queueEmpty(q))
	{
		q->front = q->rear = n ;
	}
	else
	{
			q->rear->next = n ;
			q->rear = n ;
	}

}

void serve(Queue * q ,QueueNode ** n )
{
	if(queueEmpty(q))
	{
		printf("Tryint to serve an empty queue.\nOperation abort\n");
		*n = NULL ;
	
	}
	else
	{
		*n = q->front ;
		q->front = q->front->next ;
		if(queueEmpty(q))
			q->rear = NULL ;
	}
}







int main(int argc , char *argv[])
{
	Queue q ;
	QueueEntry input ;
	int i ;
	createQueue(&q);
	QueueNode * temp ;

	while(true)
	{
		printf("Enter your option \n1.Append\n2.Serve\n3.exit\n ");
		scanf("%d",&i);
		getchar();
		switch(i)
		{
			case 1 :printf("Enter your element \n");
					scanf("%c",&input);
					append(&q,newQueueNode(input));
					break ;
			case 2 :serve(&q,&temp);
					
					if(temp != NULL)
					printf("deleted Node is %c\n",temp->info);
					free(temp);
					break ;
			case 3 :
					return 1 ;
					break ;
			default:printf("Enter proper option \n");
					break ;

		}
		sleep(1);
		system("clear");
	}

}






















