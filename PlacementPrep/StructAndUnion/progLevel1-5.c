#include <stdio.h>

struct circle {float r ;} ;

void f(struct circle * t)
{
	t[0].r = 12.3 ;
	t[1].r = 13.5 ;

}

main()
{
	struct circle t[] = {4.5,5.5};
	f(t);
	printf("%f %f \n",t[0].r, t[1].r);
}