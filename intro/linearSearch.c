#include <stdio.h>

int main()
{
    int n;
    int i;
    int f;
    printf("how many number of number would you like to insert into array");
    scanf("%d",&n);
    int array[n];
    printf("enter the %d elements ",n);
    for(i = 0 ; i < n ; i++)
        scanf("%d",&array[i]);
    printf("enter any element to find in array or not ");
    scanf("%d",&f);
    i=0;
    while(i<n)
    {
        if(f==array[i])
        {
            printf("element is found in the place of %d",i+1);
            break;
    
        }
    i++;
    }


}
