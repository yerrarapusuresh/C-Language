#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAXTHREADS	20
#define NMAX	        1000000

void *randint(void *);
int count[MAXTHREADS], tcount;

int main(int argc, char *argv[])
{
     int i, nthreads;
     pthread_t tid[MAXTHREADS];

     nthreads = atoi(argv[1]);
     tcount = 0;

     for (i=0; i<nthreads; i++) {
	  count[i] = 0;
	  if (pthread_create(&tid[i], NULL, randint, (void *)&i) != 0) {
	       fprintf(stderr, "Error creating thread %d\n", i);
	       exit(1);
	  } else {
	       printf("Created Thread %d\n", i);
	  } 
     }

     for (i=0; i<nthreads; i++) {
	  printf("Waiting for thread %d to terminate\n", i);
	  pthread_join(tid[i], NULL);
     }

     for (i=0; i<nthreads; i++) {
	  printf("Count for Thread %d: %d\n", i, count[i]);
     }

     exit(0);
}

void *randint(void *pint)
{
     int j, k;
     int rseed;

     j = *((int *)pint);
     printf("Started thread %d\n", j);
     while (tcount++ < NMAX) {
	  count[j] += 1;
     }
     return(NULL);
}