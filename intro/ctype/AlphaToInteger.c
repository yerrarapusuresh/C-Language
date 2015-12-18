#include <stdio.h>
#include <stdlib.h>

int alphaToNumaric(char string[]);

int main()
{
    char input[10];
    
    printf("Enter the any number\n");
    scanf("%d",input);
    
    int number = alphaToNumaric(input);
    number = atoi(input) ;
    
    printf("%d\n",number);
    printf("%d\n",number);
    
}

int alphaToNumaric(char string[])
{
    int Value = 0 ;
    int i;
    
    for(i = 0 ; string[i] >= '0' && string[i] <= '9' ; i++)
          
            Value = Value * 10 + ( string [i] - '0' ) ;
        
    
    
    return Value ;
    
}
