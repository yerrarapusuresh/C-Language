#include <stdio.h>
#include <stdbool.h>
#include "linkedlist.h"


int main()
{
	Node * head = NULL ;
	int input ;


	while(true)
	{
		printf("Enter your option\n\t\t1.Insert\n\t\t2.Reverse List\n\t\t3.Print List\n\t\t4.Exit\n");
		scanf("%d",&input);		
		switch(input)
		{
			case 1 :	printf("enter an element to insert into list \n");
						scanf("%d",&input);
						push(&head,newNode(input));
						break ;
			case 2 : 	listReverse(&head);
						break ;
			case 3 :	printList(head);
						break ;
			case 4 :	return 0 ;
						break ;
			default :	printf("Enter proper option\n");
		}
	}
}
