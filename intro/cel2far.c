#include <stdio.h>

int main(void)
{
    int lower=0;
    int upper=300;
    int far;
    int cel=0;
    far = lower; 
    printf("\t%s","far to cel convertion\n");  
    while(far<=upper)
    {
        cel = 5 * (far - 32) / 9;
        printf("%3d%5d\n",cel,far);
        far += 30;  
    }






}
