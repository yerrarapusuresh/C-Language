/*********************************************************************************************************************
 *AUTHOR : SURESH YERRARAPU 
 *
 * THIS PROGRAM IS ABOUT INTEGER PALINDROME 
 *
 *
 *DESCRIPTION : IT'S READS ANY FIVE DIGIT NUMBER THEN IT CHEKC WHETHER IT IS PALINDROME NUMBER OR NOT !
 *
 * ********************************************************************************************************************/
    
    
    


#include <stdio.h> 
    
int reverse(int num);
void isPalin(int num);

int main()
{
        char nnum[10] ;
        int rev,num,flag=0;
        do{
                if(flag > 0)
                        printf("you entered Wrond Input. Please enter valid five digit number  \n");
                flag++;
                printf("Enter any number five digit number  :\n");
                scanf("%s",nnum);
                num = atoi(nnum);
        }while((num > 100000) || (num < 9999));

        isPalin(num);


}

//It reverses the riven number and returns reversed number
int reverse(int num)
{
        int rem = 0;
        int rev = 0 ;

        while (num != 0)
        {
                rem = num % 10 ;
                num = num / 10 ;
                rev = rev * 10 + rem;
        }

        return rev ;
}

//it is check the given number is palindrome or not
void isPalin(int num )
{
        int rev = reverse(num);
        if(num == rev )
                printf("Yes!, given number is Palindrom .\n");
        else
                printf("No!, given number is not palindrome.\n");
}















