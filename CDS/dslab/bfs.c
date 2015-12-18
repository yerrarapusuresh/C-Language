#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
	int data ;
	struct node * next ;
}Node ;
void push(Node ** Head , int data);
void nulFy(char* , int);
void disply(Node * head );
void makeItNull(Node * array[],int size);

int main(int argc ,char* argv[])
{
	FILE * fp = NULL ;
	char buff[5];
	int size = atoi(argv[1]) + 1;
	Node * arrayList[size];
	makeItNull(arrayList , size ) ;

	
	int c,i = 0,temp , edge1 = -1 ,edge2 = -1 ,counter = 0  ;

	if (argc != 3 )
	{
		printf("Usage :./program size inputFile \n");
		return -1 ;
	}
	if( (fp = fopen(argv[2],"r")) == NULL)
	{
		printf("file could  not opend !\n");
		return -1 ;
	}
	while( (c = fgetc(fp)) != EOF)
	{
		if( (c <= '9') && (c >= '0'))
		{
			buff[i]	= c ;
			i++;
		}
		else
		{	temp = atoi(buff) ;
		
			if( temp  >  0 )
			{
				counter ++ ;
				if(counter == 1)
					edge1 = temp ;
				if(counter == 2 )
				{
					edge2 = temp ;
					if( edge1 >=  size || edge2 >= size )
					{
						printf("Some edges are greter than Size \n");
						return -1 ;
					}
					push(&arrayList[edge1],edge2);
					push(&arrayList[edge2],edge1);
					counter = 0 ;
				}
			}
			
			i = 0 ;
			nulFy(buff,5) ;
			
		}
	}
	for( i = 0 ; i < size ;i++ )
	{
		printf("items in %d:",i);
		disply(arrayList[i]);
		printf("\n");

	}
	fclose(fp);
	
}	


void nulFy(char input[],int size)
{
	int i ;
	for (i = 0 ; i < size ; i++)
		input[i] = '\0' ;

}

void makeItNull( Node * array[],int size)
{
	int i ;
	for( i = 0 ; i < size ; i++)
		array[i] = NULL ;
}

void push( Node ** headRef , int data )
{
	Node * newNode = malloc(sizeof(Node));
	newNode -> data = data ;
	newNode->next = *(headRef) ;
	*headRef = newNode ;
}
void disply(Node * head )
{
	Node * temp = head ;
	while(temp != NULL)
	{
		printf("%d \t",temp->data);
		temp = temp->next ;
	}

}









