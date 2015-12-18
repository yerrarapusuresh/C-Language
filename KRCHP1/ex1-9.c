#include <stdio.h>

int main()
{
	int c ;
	int lastChar = ' ' ;
	while ((c = getchar() ) != EOF)
	{
		if (c != ' ')
			putchar(c);
		if (c == ' ')
			if (lastChar != ' ')
				putchar(c);
		lastChar = c;
	}
}
