#include <stdio.h>

int sort(int array[] ,int size )
{
	int i , j , curr;
	for(i = 0 ; i < size-1 ; i++)
	{
		j = i+1;
		curr = array[j] ;
		while(j > 0 && array[j-1] > curr)
		{
			array[j] = array[j-1] ;
			j-- ;
		}
		array[j] = curr ;
	}
}

int main()
{
	int array[] = {4,3,7,4,4,100};
	sort(array,6);
	int i ;
	for(i = 0 ; i < 6 ; i++)
		printf("%d\n",array[i] );
}

