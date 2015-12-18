#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int rightToLeft(int input , int shift)
{
 return (input >> shift) |(input << (32 - shift));
}

int leftToRight(int input , int shift)
{
	return (input << shift) |(input >>(32 - shift));
}

int main()
{
	int input , shift ,sw;

	while(true)
	{
	printf("Enter your options\n\t1.rightToLeft Shift\n\t2.leftToRight Shift\n\t3.Exit\n");
	scanf("%d",&sw);
	switch(sw)
	{

		case 1 :printf("Enter your number: \n");
				scanf("%d",&input);
				printf("Enter your shift value \n");
				scanf("%d",&shift);
				printf("result : %d \n",rightToLeft(input,shift));
				break ;
		case 2 :printf("Enter your number: \n");
				scanf("%d",&input);
				printf("Enter your shift value \n");
				scanf("%d",&shift);
				printf("result : %d \n",leftToRight(input,shift));
				break ;
		case 3 : return 0 ;
		default :printf("Enter proper number between 1-3\n");
					break ;
	}

}
	


}
