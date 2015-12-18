#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct node 
{
	int data ;
	struct node * next ; 
} ;

void Push (struct node **HeadRef , int input)
{
	struct node * newNode = malloc(sizeof(struct node)) ;
	newNode->data = input ;
	newNode->next = *HeadRef ;
	*HeadRef = newNode ;
}
void Pop(struct node **HeadRef)
{
	struct node * temp = *HeadRef ;
	if(temp == NULL)
	{
		printf("Stack is empty \n");
	}
	else 
	{
		*HeadRef = (*HeadRef)->next ;
		printf("the deleted item is %d \n",temp->data);
		free(temp);
	}
	
}

void Disply (struct node * Head )
{
	struct node * temp = Head ;
	while(temp != NULL)
	{
		printf("\t%d\n",temp->data);
		temp = temp->next ;
	}
}

void makeItFree(struct node * Head)
{
	struct node * temp = Head ;
	while(temp != NULL)
	{
		Head = Head -> next ;
		free(temp);
		temp = Head ;
	}
}




int main()
{
	
	int input  ;
	bool repeat = true ;
	struct node * Head = NULL ;

	while(repeat)
	{
		printf("Enter your option : \n\t1.Push\n\t2.Pop\n\t3.Disply\n\t4.Exit\n\tINPUT :");
		scanf("%d",&input);
		switch(input)
		{
			case 1 :printf("Enter any number to push \n");
				scanf("%d",&input);
				Push(&Head , input) ;
				break ;
			case 2 :printf("in the area of pop\n");
				Pop(&Head);
				break ;
			case 3 :printf("the following elements are in the stack \n"); 
				Disply(Head);
				break ;
			case 4 :printf("good Bye \n"); 
				makeItFree(Head);
				return 0 ;
				break ;
			default : printf("enter proper INPUT \n");
		}
	
	}
return 0 ;
}























