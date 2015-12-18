#include <stdio.h>

#define OUT 0
#define IN 1
int main()
{
    int c;
    int nw,nc,nl;
    nw = nc = nl = 0;
    int state = OUT ;
    while((c=getchar()) != EOF)
    {   
        nc++;
        if( c == '\n' )
            nl++;
        if( c == ' ' || c == '\n' || c == '\t')
            state = OUT;
         else if(state == OUT)
         {
            nw++;
            state = IN;
         }
    
    }
    printf("%d %d %d",nl,nw,nc);
}

