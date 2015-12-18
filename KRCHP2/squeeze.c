#include <stdio.h>

void squeeze(char array[],char elim);

int main()
{
	char inputArray[10] ;
	char inputChar ;

	printf("\nEnter elimination character : ");
	//scanf("%c",&inputChar);	
	inputChar = getchar();

	printf("Enter any String : ");
	scanf("%s",inputArray);
	
	
	
	

	squeeze(inputArray,inputChar);
	printf("\nAfter elimination : %s \n",inputArray);

}
void squeeze(char array[], char elim)
{
	int i, j ; 
	for (i = 0,j = 0 ; array[i] != '\0' ; i++)
		if(array[i] != elim)
			array[j++] = array[i] ;
	array[j] = '\0' ;
			
}
