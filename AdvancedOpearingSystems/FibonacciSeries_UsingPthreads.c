/*Program 2 : Fibonacci Series using Pthread techqniques executed in Linux
NAME : LALITHA MADHURI PUTCHALA
MY CENTRAL ID : 700657631*/
/*Including all necessary library files for the program*/
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/syscall.h>
/*Declaring variables and pthread variables*/
int length;
int fib[2048];
pthread_t tidFib;
pthread_attr_t attr;


	

void *generateFibonacciSeq()
{
	int prev = 0, curr = 1;
	fib[0] = 0;
	fib[1] = 1;
        int i;
	for(i =2; i < length; i++){
		fib[i] = prev + curr;
		prev = curr;
		curr = fib[i];	
	}
}
/*Main Method*/
int main(int argc, char *argv[])
{
        length = atoi(argv[1]);

        pthread_attr_init(&attr);
        pthread_create(&tidFib,&attr,generateFibonacciSeq, NULL);
        pthread_join(tidFib,NULL);
        int i;
        for( i = 0; i < length; i++){
                printf ("%d ", fib[i]);
        }

        printf("\n");
        return 0;
}


