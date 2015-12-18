#include <stdio.h>

#define  MIN  0

int main()
{
	float fah ,cel ;
	for (fah = 300; fah >= MIN ;fah -= 20)
	{
		cel = ((5)*(fah-32))/9;
		printf("%6.7f\t%6.8f\n",fah,cel);
	}
}
