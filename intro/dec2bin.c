#include <stdio.h>
void call(int * array)
{
int i;
for(i=0;i<10;i++)
    array[i]=i;

}
int main()
{
    int array[10];
    call(array);
    printf("%d",array[7]);

}
