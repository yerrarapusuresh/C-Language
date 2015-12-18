#include <stdio.h>

void func(int x)
{
	if (x > 0)
	func(--x);
	printf("%d" , x);
}
int main()
{
func(0);
return 0;
}