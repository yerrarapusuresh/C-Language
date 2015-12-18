/*******************************************************************************************************************************
*AUTHOR : SURESH YERRARPU 
*THIS PROGRAM ABOUT PRIORITY QUEUE BY USING LINKED LIST 
*
*
*DISCRIPTION : IT'S READS EACH INPUT FROM input FILE LOAD TO SINGLE LINKED LIST WHILE READS ITS SORTED THEN WRITE TO FILE .
*****************************************************************************************************************************/





#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
	int data ;
	struct node * next ;
}NODE ;

void makeList (NODE ** headRef , int input);
void displayList(NODE * head ) ;
void makeItFreeList(NODE **HeadRef);
void InsertPosition(NODE **HeadRef, int data );
void writeFile(FILE *fp,NODE * head ) ;

int main(int argc, char* argv[])
{
	

	FILE *Fin  ;
	FILE *Fout ;

	char buffer[100];
	
	int input ; 
	NODE * Head = NULL ;


	if(argc != 3)
	{
		printf("Please is enter input and output files ! \n");
		return -1 ;
	}
	
	
	if((Fin =  fopen(argv[1] , "r")) == NULL)
	{
		printf("Input file is could not opened !\n");
		return -1 ;
	}
	
	if((Fout = fopen(argv[2] ,"w")) == NULL)
	{
		printf("Outpuf file is could not opend !\n");
		return -1;
	}

	while(fgets(buffer,100,Fin) != NULL)
		{
			input = atoi(buffer);
			if(input != 0)
			{
			
			if((Head == NULL)||(Head->data > input))
			{
				makeList(&Head,input);
			}
			else
			{
				NODE * current = Head ;
				while((current ->next != NULL) && ((current->next->data) < input))
					{
						current = current->next ;
					}
					makeList(&current->next , input);
			}}

			
		}
//	displayList(Head);
	writeFile(Fout,Head);
	makeItFreeList(&Head);
	fclose(Fin);
	fclose(Fout) ;

}

//It's write all inputs to the file 
void writeFile(FILE * fp,NODE * head )
{
	NODE * temp = head ;
	while(temp != NULL)
	{
		fprintf(fp,"%d\n",temp -> data );
		temp = temp -> next ;
	}
	
}

// Its build list 
void makeList(NODE ** headRef , int data )
{
	NODE * newNode = malloc(sizeof(struct node)) ;
	newNode->data = data ;
	newNode->next = *headRef ;
	*headRef = newNode ;
	
}

//It's Displys input variables allocated by the user 
//It's only for debugging purpose 
void displayList(NODE * head)
{
	NODE * temp = head ;
	while(temp != NULL)
	{
		printf("%d\n",temp->data);
		temp = temp->next ;
	}
}

//It'free all heap memory before program exits 
void makeItFreeList(NODE **HeadRef)
{
	NODE * current = *HeadRef ;
	NODE * pointer ;
	while(current != NULL)
	{
		pointer = current->next ;	
		free(current);
		current = pointer ;
	}
	*HeadRef = NULL ;
	
}


//debugging purpose 


/*
void InsertPosition(NODE **HeadRef, int data )
{
	NODE * newNode = malloc(sizeof(struct node ));
	newNode->data = data ;
	
	if(*HeadRef == NULL || (*HeadRef)->data <= newNode->data)
	{
		newNode->next = *HeadRef ;
		*HeadRef = newNode ;
		
	}
	else {
	NODE * pointer	= *HeadRef ;
	while(pointer != NULL && pointer->next->data < newNode->data)
	{
			pointer = pointer->next ;

	}
	newNode->next = pointer->next ;
	pointer->next = newNode ;


		}
}

*/




































