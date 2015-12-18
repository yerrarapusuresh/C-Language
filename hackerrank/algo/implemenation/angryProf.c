#include <stdio.h>
#include <stdlib.h>


int main()
{
	int size ;
	scanf("%d",&size);

	int i = 0 ;
	int res[size];

	while(i < size)
	{
		int n , k ;
		scanf("%d %d",&n,&k);

		int j = 0 ;
		int input ;
		int counter = 0 ;

		for(j = 0 ; j < n ; j++)
		{
			scanf("%d",&input);
			if(input < 1)
				counter++ ;


		}if(counter >= k)
			res[i] = 1;
			else res[i] = 0;

		i++ ;
	}
	for( i = 0 ; i < size ;i++)
		if(res[i])
			printf("NO\n");
		else
			printf("YES\n");
}