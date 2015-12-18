#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* strcpy1(const char* str );
int main ()
{
    char * name ;
    name = malloc(sizeof(char)) ;
    scanf("%s",name);
    printf("%s",name);
    char * dup ;
    dup = strcpy1(name);
    printf("%s",dup);
    free(dup);
        

}
char* strcpy1(const char* str)
{
    char* dup;
    int len;
    len = strlen(str) + 1;
    dup = malloc(sizeof(char)*len);
    strcpy(dup,str);
    return dup;
    

}

