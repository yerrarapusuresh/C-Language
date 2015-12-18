#include <stdio.h>

int main()
{
    int numDigits[10];
    int whiteSpace = 0;
    int otherChars = 0;
    int i ;
    int c ;
    for ( i = 0; i < 10 ; i++ )    
            numDigits[i] = 0 ;
    while((c = getchar()) != EOF )
    {
        if( c >= '0' && c <= '9' )
            ++numDigits[c - '0'];
        else if( c == ' ' || c == '\n'|| c == '\t')
            whiteSpace++;
        else
            otherChars++;
    }
    
    for(i = 0 ; i< 10 ; i++)
            printf("\t%d   -- %d\n",i,numDigits[i]);
    printf("\tWhiteSpace -- %d\n",whiteSpace);
    printf("\tOtherChars -- %d\n",otherChars);
     return 0;
    
}

