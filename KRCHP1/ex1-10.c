#include <stdio.h>

int main()
{
	int c ;
	while((c = getchar()) != EOF)
	{
		if (c == '\t')
			printf("\\t");
		else if (c == ' ')
			printf("\\b");
		else if (c == '\\')
			printf("\\\\");
		//if((c != '\t') && (c != '\b') && (c != '\\'))	
		else
			putchar(c);
	}
}
