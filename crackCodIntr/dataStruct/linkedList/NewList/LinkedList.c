#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"


void push(Node ** head , Node * newnode)
{
		newnode->next = *head ;
		*head = newnode ;
}

void listReverse(Node ** head)
{
	Node * next , * result = NULL , * current = *head ;
	while(current)
	{
		next = current->next ;
		push(&result,current);
		current = next ;
	}
	*head = result ;
}
void printList(Node * head)
{
	if(!head)
		printf("List is empty nothing to print");
	else
	{	
		printf("elements in the list \n");
		while(head)
		{
			printf("%d\t",head->data);
			head = head->next ;

		}

	}
	printf("\n");
}

Node * newNode(int data)
{
	Node * newnode = (Node *) malloc(sizeof(Node));
	newnode->data = data ;
	newnode->next = NULL ;
	return newnode ;
}