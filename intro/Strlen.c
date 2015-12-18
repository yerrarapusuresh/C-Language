#include <stdio.h>
#include <stdlib.h>

int str_len(char * str);

int main()
{
    char* str = malloc(sizeof(char) * 15);
    scanf("%s",str);
    printf("%d",str_len(str));
    free(str);
}

int str_len(char * str)
{
    int i=0;
    while(str[i] != '\0')
        ++i;
    
    return i;
}
