#include <stdio.h>

int main()
{
	int c,nl ;
	while((c = getchar() )!= EOF)
	{
		if(c == '\n')
			++nl;
	}
	
	printf("Number of lines : %d\n",nl);
}
