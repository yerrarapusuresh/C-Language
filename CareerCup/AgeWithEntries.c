#include <stdio.h>
#define MAX 120

int main()
{
		static int age[100];
		int i ;
		int loopLimit;
		int input ;

		printf("How many entries would you like to enter");		
		scanf("%d",&loopLimit);

		for(i = 0 ; i < loopLimit ;i++)
		{
			printf("enter you element \n");
			scanf("%d",&input);
			age[input] += 1 ;

		}

		for(i = 0 ; i < MAX ;i++)
		{
			if(age[i] != 0)
				printf("%d : %d\n",i ,age[i]);
		}



		return 0 ;
}