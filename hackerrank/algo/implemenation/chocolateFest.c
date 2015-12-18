#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int t, n, c, m;
    scanf("%d", &t);
    while ( t-- )
    {
        scanf("%d%d%d",&n,&c,&m);
        int ans = 0 ; 
        ans = n / c;
        int temp = ans /m ;
        if(temp)
            if((temp + ans % m) >= 2)
            temp++ ;
        
            
        
            
        
        
         
        printf("%d\n",ans+temp);
            
        
        
        
    }
    return 0;
}
