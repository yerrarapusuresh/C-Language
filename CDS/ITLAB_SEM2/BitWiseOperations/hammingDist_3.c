#include <stdio.h>

findNumOne(int input)
{
	int res = 0 ;
	for(;input != 0 ;input >>=1)
		if(input & 01)
			res++ ;
return res ;
}

int main()
{

	int input , i, min = 999 , max = 0 ,res1,a,b,c,d;
	printf("enter number array length  \n");
	scanf("%d",&input);

	int array[input];
	for( i = 0 ; i < input ; i++)
		scanf("%d",&array[i]);

	for(i  = 0 ; i < input-1; i++)
	{
		res1 = findNumOne(array[i]^array[i+1]);
		if(res1 < min)
		{
			min = res1 ;
			a = array[i];
			b = array[i+1];

		}
		if(res1 > max)
		{
			max = res1 ;
			c = array[i];
			d = array[i+1];
		}
	}

	printf("min : dist %d .elements{%d %d }\nmax : dist %d .elements {%d %d}\n",min,a,b,max,c,d);
//	for( i = 0 ; i <  input ;i++)
//		printf("%d\n",array[i]);
}
