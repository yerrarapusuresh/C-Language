#include <stdio.h>

char f(char s , char t)
{
	s = 'B';
	t = 'A';
	return s<t ? s : t ;
}

int main()
{
	char a  = 'A',b = 'B',r;
	r = f(a,b);
	printf("%d %d %c\n",a,b,r);
	return 0 ;
}
