#include <stdio.h>

int main()
{
	 long long ans = 1 ;
	int input ;
	scanf("%d",&input);
	 long long i ;
	for(i = input  ; i >= 1 ;i--)
		ans = ans * i ;
	printf("%lld",ans);

}