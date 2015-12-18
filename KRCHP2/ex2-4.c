#include <stdio.h>

void SqueezeVer2(char input[],char elim[] );

int main()
{
	char inputArray[10] ,inputArray2[10];
	
	printf("Enter any String one : ");
	scanf("%s",inputArray);

	printf("Enter  String two :" );
	scanf("%s",inputArray2);
	
	SqueezeVer2(inputArray , inputArray2);
	printf("%s  %s\n",inputArray,inputArray2);
	return 0 ;
}


void SqueezeVer2(char input[] ,char elim[])
{

	int i , j , k ;
	for (i = 0 ; elim[i] != '\0'; i++)
	{	
		k = 0 ;
		for(j = 0 ; input[j] != '\0'; j++)
		{
			if(input[j] != elim[i] )
				input[k++] = input[j];
		}
			input[k] = '\0';
	}
}



















