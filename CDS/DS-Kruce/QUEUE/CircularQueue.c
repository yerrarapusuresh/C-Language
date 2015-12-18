#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char QueueEntry ;

typedef struct queueNode
{
	QueueEntry info ;
	struct queueNode * next ;
} QueueNode ;

typedef struct cirQueue
{
	 QueueNode * rear ;
}Queue ;

void append(Queue * q , QueueNode * n)
{
	if(!n)
		printf("Tying to insert empty node .\nOperation aborted \n");
	else if (q->rear == NULL )
		{
			q->rear = n ;
			n->next = q->rear ;
		}
	else
	{
		n->next = q->rear->next ;
		q->rear->next = n ;
		q->rear = n ;
	}
}
bool queueEmpty(Queue * q )
{
	if(q->rear == NULL)
		return true ;
	else
		return false ;
}

void serve(Queue * q , QueueNode ** n )
{
	if( queueEmpty(q) )
	{
		printf("Trying to serve on empty Queue \nOpeartion is aborted\n");
		*n = NULL ;
	}
	else
	{
		if(q->rear == q->rear->next)
		{	
			*n = q->rear ;
			q->rear = NULL;
		}
		else
		{
				*n = q->rear->next ;
				q->rear->next = q->rear->next->next ;
		}
	}
}
QueueNode * newQueueNode (QueueEntry e)
{
	QueueNode * newNode = malloc(sizeof(QueueNode));
	newNode ->info = e ;
	newNode->next = NULL ;
	return newNode ;
}




void createQueue(Queue * q)
{
	q->rear = NULL ;
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















































