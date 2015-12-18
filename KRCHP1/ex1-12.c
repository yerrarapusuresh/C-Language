#include <stdio.h>
#define IN 1
#define OUT 0


int main()
{
	int c ,nl,nw,nc,state;
	
	nw = nc = nl = 0 ;
	while((c = getchar()) != EOF)
	{
		++nc ;
		if(c == '\n')
			++nl;
		if(c == '\n' || c == ' ' || c == '\t')	
			state = OUT ;
		else if (state == OUT)
			{
				++nw;
				state = IN ;
			}
	}
	printf("\n\tNumber of Words :%d\n\tNumber of lines :%d\n\tNumber of characters  :%d\n",nw,nl,nc);
	
}
