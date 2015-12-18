
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
/*
 * Complete the function below.
 */
int maxXor(int l, int r)
 {
 	int temp = 1 , prev = 0;
 	for(;temp < l ; temp = temp << 1) ;

 		printf("%d\n",temp);
    for(  ; temp < r; temp = temp<<1) ;
    	printf("%d\n",temp);
    	
    if(temp > r)
    	temp = temp >> 1;
    printf("%d\n",temp);
    if(temp > r || temp < l)
    	return (l+r)/2 ^(((l+r)/2)-1);
    return  temp ^ (temp - 1) ;



}
int main() {
    int res;
    int _l;
    scanf("%d", &_l);
    
    int _r;
    scanf("%d", &_r);
    
    res = maxXor(_l, _r);
   printf("%d", res);
    
    return 0;
}