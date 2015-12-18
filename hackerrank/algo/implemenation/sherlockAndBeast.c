#include <stdio.h>

int main()
{
	int tsize,input ,i,j,f;
	scanf("%d",&tsize);


	while(tsize--)
	{
		scanf("%d",&input);
		f = 0 ;
		if(input % 5 == 0)
		{
			f = 1 ;
			for( i = 0 ; i < input ; i++)
				printf("3");
			printf("\n");
		}
		else if(input % 3 == 0)
		{
			f = 1;
			for(i = 0 ; i < input ; i++)
				printf("5");
			printf("\n");
		}

		for( i = 1 ; i * 3 < input ; i++)
		{
			if(((input - i * 3)% 5) == 0)
			{
				f = 1 ;
				for( j = 0 ; j < i ; j++)
				{
					printf("555");
				}
				for(j = 0 ; j < (input - i * 3) ; j++)
					printf("3");
				i = i+input ;
				printf("\n");

			}

		}
		if(!f)
			printf("-1\n" );
		
		
	}
}