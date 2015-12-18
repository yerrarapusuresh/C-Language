/*******************************************************************************************
*AUTHOR : SURESH YERRARAPU 								   *
*THIS PROGRAM ABOUT DUPLICATE ELIMINATION .						   *
*DEDCRIPTION : AS EACH NUMBER READS FROM USER IT IS INTIMATE'S ABOUT DUPLICATE NUMBER ;	   *
*											   *
*******************************************************************************************/





#include <stdio.h>
#include <stdbool.h>


bool isDuplicate(int array[], int input) ;
void printList(int array[]);
void nullifyArray(int array[]);
void getInput(int array[]);



int main()
{
	//int counter = 0,input = 0 ,i;
	int array[20] ;
	//char  input_char[1000] ; 
	
	nullifyArray(array) ;
	getInput(array);
	
	printList(array);
	return 0 ;


}

// it returns whther given input in duplicate or not 
bool isDuplicate(int array[], int input)
{
	int i ;
	static int arrayPointer = 0 ;//keep track of position of array 
	for (i = 0 ; i < 20 ; i++ )	
	{
		if( array[i] == input) 
			return true ;
	}
	
	array[arrayPointer++] = input ;
	return false ;
	
}

//prints entire list 
void printList(int array[])
{
	int i ;
	printf("\n\n\n\n\nNumbers in the list\n");
	for( i = 0 ; i < 20 ; i++ )
		printf("\t\t\t\t%d\n",array[i]);
}

//It going to set all variables to zero 
void nullifyArray(int array[])
{
	int i ;
	for( i = 0 ; i < 20 ; i++ )
		array[i] = 0 ;
}

//it takes input from user and cheacks given input is already entered or not by using isDuplicate function
void getInput( int array[] )
{
		int counter , input ;
		char input_char[100];

		while(counter < 20 )
			{
				printf("enter number %d :",counter+1);		
				scanf("%s",input_char);
				input = atoi(input_char) ;
				if((input < 10) || (input > 100))
					printf("please of enter any number between 10 and 100 \n");
				else {
	
	
					if(isDuplicate(array , input))
					{	
						printf("entered duplicate\n");		
					}
					else
					{
						counter ++ ;
					}
				}
	
			}
}

