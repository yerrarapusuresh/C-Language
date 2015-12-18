#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef  struct node
{
	int item ;
	struct node * next ;
}Node; 

typedef struct list
{
	Node * Head ;
	Node * Tail ;
	int length ;
}List ;
void init(List * l)
{
	l->Head = NULL ;
	l->Tail = NULL ;
	l->length = 0 ;
}

void print_list(List * l)
{
	//if(l->Head == NULL)
	//	printf("List is empty \n");
	//else
	//{
		Node * temp = l->Head ;
		printf("element in the list :\n");
		while(temp)
		{
			printf("%d\t",temp->item);
			temp = temp->next ;
		}
		printf("\n");
	//}//
}
Node * newNode(int element)
{
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->item = element ;
	newNode->next = NULL ;
	return newNode ;
}

void insert_element(List * l , Node * newNode )
{
	if(l->Head == NULL )
	{
	//	newNode->next = NULL ;
		l->Tail = l->Head = newNode;

	}
	else
	{
		l->Tail->next  = newNode ;
		l->Tail = l->Tail->next ;
	//	l->Tail->next = NULL ;
	//	l->length += 1 ;
	}
}


void sorted_merge(List * l,List * l1 , List * l2)
{
	if(l1->Head && l2->Head)
	{
		l->Head = (l1->Head->item < l2->Head->item) ?  l1->Head :l2->Head ;
		Node * temp ;

		while(l1->Head && l2->Head)
		{
			if(l1->Head->item < l2->Head->item)
			{ 
				while(l1->Head->next != NULL && l1->Head->next->item < l2->Head->item)
					l1->Head = l1->Head->next ;

				temp = l1->Head->next ;
				l1->Head->next = l2->Head ;
				l1->Head = temp ;
			}
			else
			{
				while(l2->Head->next != NULL && l2->Head->next->item < l1->Head->item)
					l2->Head = l2->Head->next ;
				temp = l2->Head->next ;
				l2->Head->next = l1->Head ;
				l2->Head = temp ;
			}

		}


	}
	else if(l1->Head)
		l->Head = l1->Head ;
	else if(l2->Head)

		l->Head = l2->Head ;
	init(l1);
	init(l2);
}

int main()
{
 List l,l1 , l2 ;
 Node n1,n2,n3,n4,n5,n6,s1,s2,s3,s4,s6 ;
 l1.Head = &n1 ;
 n1.item = 1;
 n1.next = &n2 ;
 n2.item = 3 ;
 n2.next = &n3 ;
 n3.item = 5 ;
 n3.next = NULL ;
 print_list(&l1);
 l2.Head = &s1;
 s1.item = 0 ;
 s1.next = &s2 ;
 s2.item = 2;
 s2.next = &s3 ;
 s3.item = 4 ;
 s3.next = NULL ;
 print_list(&l2);
 sorted_merge(&l,&l1,&l2);
 print_list(&l);

}
















