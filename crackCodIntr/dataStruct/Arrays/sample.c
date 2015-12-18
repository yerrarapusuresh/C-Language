#include <stdio.h>
#include <omp.h>

int main()
{
	omp_set_num_threads(10);
	#pragma omp parallel

	printf("hellow world %d \n",omp_get_thread_num());
}