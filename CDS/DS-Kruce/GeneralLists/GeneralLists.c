#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef char ListEntry ;

typedef struct listNode 
{
	ListEntry info ;
	struct listNode * next ;
}ListNode ;

typedef struct list
{
	ListNode * head ;
	ListNode * rear ;
	int counter ;
}List ;

typedef int Position ;


void createList(List * l)
{
	l->head = NULL ;
	l->rear = NULL ;
	l->counter = 0 ;
}

bool listEmpty(List * l)
{
	if(l->counter == 0)
		return true ;
	else
		return false ;
}
ListNode * newListNode(ListEntry nodeValue)
{
	ListNode  * newNode = malloc(sizeof(ListNode));
	
	newNode->info = nodeValue ;
	newNode->next = NULL ;

	return newNode ;
}

void append(List * l , ListNode * newNode)
{
	if(!newNode)
	{
		printf("Trying to insert empty node : Operation abort\n");

	}

	else
	{
		if(l->counter == 0)
		{
			l->head = l->rear = newNode ;
		}
		else
		{
			l->rear->next = newNode ;
			l->rear = l->rear->next ;
		}
		l->counter ++ ;
	}

}

void removeFront(List * l , ListNode ** ln)
{
	if(listEmpty(l))
	{
		printf("Trying to remove on empty list :Operation abort \n");
		*ln = NULL ;
	}
	else
	{
		*ln = l->head ;
		l->head = l->head->next ;
		l->counter-- ;
		if(l->counter == 0)
			createList(l);
	}

}

void displyList(List * l)
{
	ListNode * pWalk = l->head ;
	printf("Items in List :\t");
	while(pWalk)
	{
		printf("%c\t",pWalk->info);
		pWalk = pWalk->next ;
	}
	printf("\n");
}
void setPosition(List * l , Position p , ListNode ** current)
{
	if((p < 0) || (p >= l->counter))
	{
		printf("Trying access Index out of bounds :Operation abort");
		*current = NULL ;
	}
	else
	{
		int count = 0 ,i;
		ListNode * temp = l->head ;
		for(i = 1 ; i <= p ; i++ )
			temp = temp->next ;
		*current = temp ;
	}
}
void insertPosition(List * l , ListNode * ln, Position p )
{
	if(!ln)
	{
		printf("Trying to insert empty Node :Operation abort");
	}
	else
	{
		if(p == 0)
		{
			ln->next = l->head ;
			l->head = ln ;
		}
		else
		{
			ListNode * current= NULL; ;
			setPosition(l,p-1,&current);
			if(current)
			{
				ln->next = current->next ;
				current->next = ln ;
			}
		}
		l->counter++ ;
	}
}

int main(int argc , char * argv[])
{
	List  l ;
	createList(&l);
	ListNode * ln ;

	ListEntry infoInput ;
	char switchInput;
	Position p ;

	while(true)
	{
		printf("Enter you Choice :\n1.Insert\n2.Remove\n3.Disply\n4.Exit\n");
		scanf("%c",&switchInput);
		getchar();
		switch(switchInput)
		{
			case '1' :printf("enter your option \n\t\t1.Insert at end\n\t\t2.insert at position\n\t\t");
					  scanf("%c",&switchInput);	
					  getchar();
					  switch(switchInput)
					  {
					  	case '1' :printf("enter you element to insert into List \n ");
					   			  scanf("%c",&switchInput);
					              getchar();
					              append(&l,newListNode(switchInput));
					              break ;
					    case '2' :printf("enter you element to insert into List \n ");
					   			  scanf("%c",&infoInput);
					              getchar();
					              printf("enter you position of element \n");
					              scanf("%d",&p);
					              getchar();
					              insertPosition(&l,newListNode(infoInput),p);
					              break ;
					    default : printf("enter proper options \n");
					    		  break ;
					   
					   

					  }

					  break ;


			case '2' : removeFront(&l,&ln);
					   if(ln)
					   		printf("entry %c removed from list\n",ln->info );
					   		
					   break ;

			case '3' : if(listEmpty(&l))
					   printf("List is empty : Nothing to print\n");
					   else
					   	displyList(&l);
					   	
					   break ;

			case '4' :printf("Thank you for using List Application \n");
					  return 0;
					  break ;
					
			default : 
					  printf("Enter proper Input\n");
					  
					  break ;

		}
		//sleep(1.5);
		//system("clear");

	}


}


















