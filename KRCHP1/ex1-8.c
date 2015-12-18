#include <stdio.h>

int main()
{	
	int c , nb = 0 ,nl = 0 , nt = 0 ;
	while ( (c = getchar ()) != EOF)
	{
		if(c == ' ')
			++nb ;
		else if (c == '\n')
			++nl ;
		else if (c == '\t')
			++nt ;
	}
	printf("number of space :%d\nnumber of new line :%d\n number of tabs :%d\n",nb,nl,nt);
}
