#include <stdio.h>
#include<stdbool.h>
bool posValue(int num , int rval)
{
	int temp = 1 <<(rval-1);
	if(num & temp) 
		return true;
	return false ;
}


int main()
{
	int input,rvalue,i , zero  = 0 , one = 0 ;


	
	printf("Enter input array length");
	scanf("%d",&input);

	int array[input];

	for( i = 0 ; i < input ;i++)
		scanf("%d",&array[i]);
	printf("enter R value to check \n");
	scanf("%d",&rvalue);
	for( i = 0 ; i < input ; i++)
	{
		if(posValue(array[i],rvalue))
			one++ ;
		else 
			zero++ ;
	}

	one>zero ? printf("ones are  high. number of ones %d\n",one):printf("zeros are high .nubmer of zero %d \n",zero );

	
}
