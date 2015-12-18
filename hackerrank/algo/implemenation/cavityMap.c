#include <stdio.h>

int main()
{
	int size ,c;
	scanf("%d",&size);

	int array[size][size];
	//char res[size][size+1];
	
	int i , j ;
	for( i = 0 ; i < size ; i++)
		for(j = 0 ; j < size ; )
			{
				c=getchar();
				if(c != '\n')
				{
					array[i][j] = c - '0';
					j++ ;
				}

			}
	for( i = 0 ; i < size ;i++)
	{
		for(j = 0 ; j < size ;j++)
		{
			if(i>0 && i < size-1 && j > 0 && j < size-1)	
				{
					if( (array[i][j] > array[i-1][j]) &&(array[i][j] > array[i+1][j]) &&(array[i][j] > array[i][j-1]) &&(array[i][j] > array[i][j+1]))
						printf("X");
					else
						printf("%d",array[i][j]);
				}
			else
				printf("%d",array[i][j] );
		}
		printf("\n");
	}

		

}
