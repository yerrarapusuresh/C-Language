#include <stdio.h>
#include <signal.h>
int ch_sig2(int);

int main(void)
{

  signal (SIGQUIT, ch_sig2);
 
  for (; ;)
    pause();

}

int ch_sig2(int sno)
{
  printf("You cannot kill me with signal %d\n", 
	 sno);
	printf("enter any number \n");
	int i ;
  scanf("%d",i);
	printf("number is %d \n",i);
  return (0);
}
