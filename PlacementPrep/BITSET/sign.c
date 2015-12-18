#include <stdio.h>

int main()
{
	unsigned int i = 1;
	int res =  -(int)((unsigned)((int)i) >>(sizeof(int)*8-1));
	printf("%d",res);
}