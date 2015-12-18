#include <stdio.h>
#include <math.h>
int main()
{
	int size ;
	scanf("%d",&size);

	while(size--)
	{
		int low , high ,i , num;
		int counter = 0  ;
		scanf("%d %d",&low,&high);
		i = ceil(sqrt((double)low));
		int j = sqrt((double)high);

		for( ; i <= j ; i++)
			counter++ ;
		printf("%d\n",counter);
	}
}