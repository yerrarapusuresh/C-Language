#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char buff[11];
    memset(buff,'\0',11);
    char c ;
    int i = 0 ;
    scanf("%s",buff);
    if((buff[8] == 'A') ||(buff[8] == 'a') )
        {
            
        buff[8] = '\0';
           printf("%s",buff);
    }
    else
        {
        i =   buff[1] - '0' ;
        printf(" %d\n",i);
        printf("%d\n",i );
        i = i + ( buff[0] - '0') * 10 ;
        i += 12 ;
        buff[1] = '0' + (i % 10);
        buff[0] = '0' + (i /10) ;
        buff[8] = '\0' ;
        printf("%s",buff);
        
    }
    
    
    return 0;
}
