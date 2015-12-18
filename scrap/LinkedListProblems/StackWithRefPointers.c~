#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
struct node 
{
	int data ;
	struct node * link ;
} ;

void Push(struct node ** headRef , int data);
int  Pop(struct node ** headRef);
void  Disply(struct node * head);
void mem_free(struct node **headRef);

int main()
{
	struct node * head = NULL;
	int n ;
	while(true)
	{
		printf("\n\tEnter your option \n\t1.Push\n\t2.Pop\n\t3.Disply\n\t4.Exit\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:	printf("\n\t Enter an element\n");
				scanf("\t%d",&n);
				Push(&head,n);
				break ;
				
			case 2: printf("\n\tPopped element is %d\n",Pop(&head));
				break ;
				
			case 3: Disply(head);
				break ;
			case 4: mem_free(&head);
				return -1;
				break ;
			cdefault: printf("Enter a proper option");
				break ;
				
		}
	}
	
	return 0 ;
}

void Push(struct node ** headRef, int data )
{
	struct node * newNode = malloc(sizeof(struct node ));
	newNode -> data = data ;
	newNode -> link = *headRef ;
	*headRef = newNode ;
	
}
int Pop(struct node ** headRef)
{
	struct node * head = *headRef ;
	int value;
	assert(head != NULL);
	value = head -> data ;
	*headRef = head-> link ;
	free(head); 	
	return value ;		
}
void  Disply(struct node * head)
{
	
	if(head == NULL)
		printf("\n\tStack is EMPTY nothig to show :D\n");
	else
	{
		printf("\n\telements current in stack\n");	
		while(head)
		{
			printf("\t%d\n",head -> data);
			head = head -> link ;
		}
	}
	
	
}

void mem_free(struct node ** headRef)
{
	struct node * head = *headRef ;
	struct node * next ;
	while(head)
	{
		next = head -> link ;
		free(head);
		head = next ;
	}
	*headRef = NULL;
}
















