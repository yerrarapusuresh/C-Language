#include <stdio.h>


int main()
{
	char ch ;
	ch = getchar();
	while (ch != EOF)
	{
		putchar(ch);
		ch = getchar();
	}
	printf("i recieved signal from the user bye \n");

}
