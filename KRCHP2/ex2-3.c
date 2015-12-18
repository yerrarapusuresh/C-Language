#include <stdio.h>

int  htoi(char array[]);

int main()
{
	char input[5];
	printf("enter any hex number : ");
	scanf("%s",input);
	printf("\n%d\n",htoi(input));
	return 0 ;
}


int  htoi(char array[])
{
	int i = 0 ;
	int num = 0 ;
	if((array[0] =='0') && (array[1] == 'x'))
		i = 2;
	if(array[0] == '0' && array[1] == 'X')
		i = 2;

	for(i ; (array[i] >= '0') && (array[i] <= '9')|| (array[i] >= 'a') && (array[i] <= 'f') || (array[i] >= 'A') && (array[i] <= 'Z');i++)
		{
			if((array[i] >= '0') && (array[i] <= '9'))
				num = num * 16 +(array[i] - '0');
			else if (array[i] >= 'a' && array[i] <= 'f')
				num = num * 16 + ((array[i] - 'a') + 10);
			else if ((array[i] >= 'A') && (array[i] <= 'F'))
				num = num * 16 + (array[i] - 'A' + 10) ;
		}
	return num ;
}
