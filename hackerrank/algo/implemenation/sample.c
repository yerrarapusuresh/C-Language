#include <stdio.h>

int main()
{

long k,n ;
scanf("%ld",&k);

long i = 1;
for ( n = i*i; i < k; i++) {
  n += 2i + 1;
  printf("%ld\n", n);
}
}