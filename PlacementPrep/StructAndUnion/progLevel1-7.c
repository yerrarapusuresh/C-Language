#include <stdio.h>

union test 
{
	short int a;
	char b ;
};

main()
{
	union test u ;
	u.a = 258 ;
	u.b = 10 ;
	printf("%d\n",u.a);
}