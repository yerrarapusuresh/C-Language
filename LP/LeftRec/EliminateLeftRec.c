#include <stdio.h>
#include <string.h>


void eliminateLeft(char production[][20], int num)
{
	int i  ;
	int index = 3 ;
	char non_terminal, alpha, beta ;
	for( i = 0; i < num; i++)
       {  
            printf("\nGRAMMAR\t:\t%s",production[i]);  

            non_terminal = production[i][0];  
            if(non_terminal == production[i][index])
             {  
                 alpha = production[i][index+1];  
                 printf(" IT IS LEFT RECURSIVE\n");  

                 while(production[i][index] != '\0' && production[i][index]!='|')  
                      index++;  
                 if(production[i][index]!='\0') 
                 {  
                      beta = production[i][index+1];  
                      printf("After Elimination :\n");  
                      printf("%c->%c%c\'",non_terminal,beta,non_terminal);  
                      printf("\n%c\'->%c%c\'|E\n",non_terminal,alpha,non_terminal);  
                 }  
                 else  
                      printf(" can't be reduced\n");  
            }  
            else  
                 printf(" is not left recursive.\n");  
            index = 3;  
       }  
}

int main()
 {  
      char non_terminal;  
      char beta,alpha;   
      int num;  
      char production[10][20];  
      int i,index = 3; 
      printf("Enter Number of Production : ");  
      scanf("%d",&num);  

      for( i = 0; i < num; i++)
        scanf("%s",production[i]);  
    eliminateLeft(production, num);
        
       
  }