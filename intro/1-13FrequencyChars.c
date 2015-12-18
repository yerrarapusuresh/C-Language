#include <stdio.h>

int main()
{
    int i,CharArray[95];
    
    for(i = 0; i < 95 ; i++)
       CharArray[i] = 0;
    while(( i = getchar()) != EOF )
    {
        if( i >= ' ' && i <= '`')
            ++CharArray[(int)i];
    }  
     for(i = 0 ;i < 95 ;i++)
        printf("%c--%d\n",i + 32,CharArray[i]);
}
