#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node 
{
	int data ;
	struct node * next ;
} ;

struct node * buildList();
void Push(struct node ** headRef , int data );
void DeleteList (struct node ** headRef ) ;
bool InsertNth(stuect node ** headRef , int pos ,int  data);
int main()
{
	struct node * head = buildList();
	struct node * Walk = head ;
	while (Walk)
	{
		printf("\n\t%d\n",Walk -> data );
		Walk = Walk -> next ;
		
	}
	DeleteList(&head);
}

struct node * buildList()
{	struct node * head = NULL ;
	struct node * tail = NULL ;
	
	int i ;
	
	for(i = 0 ; i < 10; i++)
	{
		if(!head)
		{
			Push(&head,i);
			tail = head ;
		}
		else 
		{
			Push(&(tail->next) , i );
			tail = tail->next ;
		}
	}
	return head ;
}

void Push(struct node ** headRef , int data )
{
	struct node * newNode = malloc(sizeof(struct node));
	newNode -> data = data ;
	newNode -> next = *headRef ;
	*headRef = newNode ;
	
	
}

void DeleteList(struct node ** headRef )
{
	struct node * current = * headRef ;
	struct node * next = NULL ;
	while(current)
	{
		next = current -> next ;
		free(current);
		current = next ;
		
	}
	*headRef = NULL ;
	
}

bool InsertNth(struct node ** headRef , int pos , int data )
{
	headRef 	
}

























