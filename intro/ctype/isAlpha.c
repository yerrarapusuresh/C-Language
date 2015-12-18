#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool IsAlpha(char c );
int main()
{
    char  c ;
    bool res;
    scanf("%c",&c);
    printf("%c",c);
    res = isalpha(c);
    printf("%d",res);
    res = IsAlpha(c);
    printf("%d",res);
    
    return 0 ;
}

bool IsAlpha(char c)
{
    if( (c>= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z' ) )
        return true;
    return false ;
    
}
