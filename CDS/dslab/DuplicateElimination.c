#include <stdio.h>

void eliminateDuplicate(int array[]);

int main()
{
	int array[10] ;
	int i ;
	for (i = 0 ;i < 10 ; i++)
	{
		scanf("%d",&array[i]);
	}
	
	
	eliminateDuplicate(array);
	return 0 ;
	
}

void eliminateDuplicate(int array[])
{
	int i , j ,flag = 0,pointer = 0;
	int element = 0 ;
	int duplicate[10] ;
	for (i = 0 ;i < 10 ; i++ )
	{
		duplicate[i] = 0 ; 
	}
	
	for (i = 0 ;i < 10 ;i++)
	{
		element = array[i] ;
		for(j = 0 ; j < 10 ; j++)
		{
			if(element != duplicate[j])
			{
				flag++ ;
			}
		}
		
		if(flag == 10 )
		{
			duplicate[pointer] = element ;
			pointer++;
			printf("%d",element);
		}
		flag = 0 ;
	
	}

}











