#include <stdio.h>

int getline( char input[] , int limit );
int strindex(char string[], char substring[]);

int main()
{
    char input[100];
    int limit = 100 ;
    int found = 0 ;
    char pattern [] = "suresh";

    
//    getline(input,limit);    
 //   printf("%s",input);

    while( getline(input,limit) >  0)
    {
        if(strindex(input , pattern) >= 0)
        {
            printf("%s",input);
            found++ ;
        }
    }
}

int  getline( char input[] , int limit )
{
    int i = 0 ;
    int c ;
    
    while(--limit > 0 && (c =  getchar()) != '\n' && c != EOF)
      input[i++] = c ;
    if(c == '\n')
        input[i++] = c ;
    input[i] = '\0';
    return i ;
    
}

int strindex(char string[], char substring[])
{
    int i , j ,k ;

    for ( i = 0  ; string[i] != '\0' ; i++ )
     {
        for( j = i , k = 0 ; string[j] == substring[k] && substring[k] != '\0'; j++,k++ )
        ;
                if(k > 0 && substring[k] == '\0')
                    return i ;
    }
    return -1 ;
}
