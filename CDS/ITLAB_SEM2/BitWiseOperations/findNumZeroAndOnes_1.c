#include <stdio.h>
int main()
{

	int input,ones, zero ;
	ones = zero = 0 ;
	printf("Enter input number :\n");
	scanf("%d",&input);

	for(;input != 0 ;input >>=1)
		if(input & 01)
			ones++ ;
		else
			zero++ ;
	printf("number ones = %d and zeros = %d \n",ones,zero);

}
