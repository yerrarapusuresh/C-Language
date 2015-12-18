#include <stdio.h>
#include <stdlib.h>


struct node {

	int data ;
	struct node * next ;	
            } ;

void buildList(struct node **headRef, int i);
void countTest(struct node *head );
int length(struct node* head );
void mem_free(struct node ** head);
int main()
{
	struct node * head = NULL ;
	struct node * tail = NULL ;
	int i ;
	for(i = 0 ; i< 5; i++)
	{
		if(head == NULL)
		{
			buildList(&head,i);
			tail = head ;
			
		}
		else
		{
		
			buildList(&(tail->next),i);
			tail = tail -> next ;
		}
	}
	
	
	countTest(head);
	mem_free(&head);
	countTest(head);
	
}

void buildList(struct node **headRef , int i )
{
	struct node * newNode = malloc(sizeof(struct node));
	newNode -> data = i ;
	newNode -> next = *headRef;
	*headRef = newNode ;
	
}

void countTest(struct node * head)
{
	printf("%d",length(head));

}

int length(struct node * head)
{
	struct node * Pwalk = head ;
	int count = 0;
	while(Pwalk)	
	{
		count++ ;
		Pwalk = Pwalk -> next ;
	
	}
	return count ;
}
void mem_free(struct node ** head )
{
	struct node * current = *head ;
	struct node * next ;
	while(current != NULL)
	{
		next = current -> next ;
		free(current);
		current =  next ;
		
	
	}
	*head = NULL ;
}
