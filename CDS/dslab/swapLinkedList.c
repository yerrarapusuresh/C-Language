#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node * next ;
	int data ;
}Node ;


Node * newNode(int i)
{
	Node * newNode = malloc(sizeof(Node));
	newNode->data = i ;
	newNode->next  = NULL ;

	return newNode ;
}

Node * insert (Node * head,Node * newNode)
{
	if(!head)
		return newNode ;
	else
	{
		Node * temp = head ;
		while(temp->next != NULL)
			temp = temp->next ;
		temp->next = newNode ;
	}
	return head ;
}


void disply(Node *head)
{
	while(head)
	{
		printf("%d\t",head->data);
		head =head->next ;
	}
	printf("\n");

}

Node * swapLinked(Node * head)
{
	Node * temp,*current ,*next ;
	current = head ;
	int i = 0 ;
	while(current)
	{
		if(current->next && current->next->next)
			next = current->next->next ;
		else 
			break ;
		temp = current  ;
		current = current->next ;
		current->next = temp ;
		temp->next = next ;
		
		if(i == 0 )
			head = current ;
		current = current->next->next ;
		i++;

	}

	disply(head);
	return head ;
}
void swap(Node ** a , Node ** b)
{
		Node * temp ;
		temp = * a ;
		* a = * b ;
		*b = temp ;

}
int main()
{
	Node * head = NULL;
	int i ;

	for( i = 1 ; i <= 6 ; i++)
		head = insert(head,newNode(i));


	disply(head);
	swapLinked(head);

	Node a,b  ;
	a.data = 1 ;
	a.next = &b ;
	b.data = 2 ;
	b.next = NULL ;
//	swap(&a,&b);
//	disply(&a);

}























