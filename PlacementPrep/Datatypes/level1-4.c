#include <stdio.h>

int main()
{
	int a ;
	char b ;
	float c ;
	unsigned int d ;
	printf("%d %d %d %d \n",sizeof(a),sizeof(b),sizeof(c),sizeof(d));
	printf("%d %d %d  \n",sizeof(a),sizeof('a'),sizeof(0.7));
	return 0 ;
}
