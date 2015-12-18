#include <stdio.h>
void makeArrayNull(int array[],int len) ;
int main()
{
	int i,j ;
	int forInt[10];
	int forCaptil[26];
	int forSmall[26];

	makeArrayNull(forInt,(sizeof(forInt)/sizeof(forInt[0])));
	makeArrayNull(forCaptil,(sizeof(forCaptil)/sizeof(forInt[0])));
	makeArrayNull(forSmall,(sizeof(forSmall)/sizeof(forInt[0])));

/*	for(i = 0 ; i < 10 ; i++)
		printf("%d",forInt[i]);
	for(i = 0 ; i < 26 ;  i++)
		printf("%d",forCaptil[i]);
*/	int c ;
	while((c = getchar()) != EOF)
	{
		if(c >= '0' && c <= '9')
			++forInt[c-'0'] ;
		if(c >= 'A'&& c <= 'Z')
			++forCaptil[c-'A'];
		if(c >= 'a' && c <= 'z')
			++forSmall[c-'a'];
	}
	
	for(i = 0 ; i < 10 ; i ++)	
	{
		if(forInt[i] > 0)
		{
			printf("%d |",i);
			for(j = 0 ; j < forInt[i] ; j++)
			{	//if(j == 0)
				//	printf("%d|",i) ;
				printf("=");
			}
			printf("\n"); }
	}
	for(i = 0 ; i < 26 ; i ++ )
	{	
		if(forCaptil[i] > 0 )
		{
			printf("%c |",('A' + i));
			for(j = 0 ; j < forCaptil[i] ; j++)
			{
			//	if(j == 0 )
			//		printf("%c |",(j+'A'));
				printf("=");
			
			}
			printf("\n");
		}
	}
	
	for(i = 0 ; i < 26 ; i ++)
	{	
		if(forSmall[i] > 0)
		{
			printf("%c |",(i+'a'));
			for(j = 0 ; j < forSmall[i]; j++)
			{
				printf("=");
			}
		printf("\n");
		}
		
	}
}

void makeArrayNull(int array[],int len)
{
	int i;
	for(i = 0 ; i < len ;i++ )	
		array[i] = 0 ;
}








