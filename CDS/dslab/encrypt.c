/************************************************************************************************************************
*AUTHOR : SURESH YERRARAPU
*
*THIS PROGRAM IS ABOUT SIMPLE ENCRYTPION LIKE CAESER CHIPER 
*
*DESCRIPTION : IT READS INPUT FROM USER THEN CHANGES EACH POSITION BY +5 LENGTH IN THIS CASE 
**************************************************************************************************************************/






#include <stdio.h>
#include <string.h>


void encrypt(char str[], int key);


int main()
{
	int ch,i = 0  ;
	int key = 5 ;
	char buffer[1000];
	printf("Please enter any string : \n ");

        while((ch = getchar()) != '\n')
	{
		buffer[i++] = ch ;
	}

	buffer[i] = '\0';
//        printf("%s",buffer);
	encrypt(buffer, key);
	printf("\nThe encrypt form is \n%s\n",buffer);
	
	
}


//It' encrypts each letter in given string by key length 
void encrypt(char str[],int key)
{	
	
	int  i;
	char   c ;
	for (i = 0 ;i < strlen(str); i++)
		{
			c = str[i];
			if ((c >= 'A') && (c <= 'Z'))
				{
					c = (((c + key) % ((int )'A'))%26) + ((int)'A') ;
					
					str[i] = (c);
				}
			else if ((c >= 'a') && (c <= 'z'))
				{	
					c = (((c + key) % ((int )'a'))%26) + ((int)'a') ;
					
					str[i] = (c);
				}
		}


}
