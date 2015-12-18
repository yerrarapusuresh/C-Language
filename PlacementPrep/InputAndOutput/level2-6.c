#include <stdio.h>

int main()
{
	int x = 0 ;
	for(;x<20 && printf("%d\n",x);x++)
		switch(x)
		{
			case 0 : x++,x*=2 ;
			case 20: x+=2 ;
			case 70: x+=6 ;
			default : x+=3 ;
			break ;
		}
}