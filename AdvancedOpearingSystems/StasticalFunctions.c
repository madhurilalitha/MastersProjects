/*Program 1: Statistical Functions Using Pthreads in C
NAME: LALITHA MADHURI PUTCHALA
MY CENTRAL ID : 700657631*/
/*Including all library files*/

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

/*Declaring pthread ids*/

 pthread_t tid[3];
 int arr[5];
 int global=10;
 char **ptr;
 int num;
 /*Method to handle three statistical functions in three different threads*/
  void* doSomeThing(void *arg)
  {
    pthread_t id = pthread_self();
    int i=1;
    int sum=0;
    int min=atoi(ptr[1]);
    
     if(pthread_equal(id,tid[0]))
      {
         printf("\n processing the 1st thread\n");
         while(i<num)
         {
          sum=sum+atoi(ptr[i]);
          i++;
         }
         printf("\n The average value is :%d\n",sum/(num-1));
      }


    if(pthread_equal(id,tid[1]))
     {
  	 printf("\n processing second thread\n");
    	 i=2;
  	 while(i<num)
   	 {
      	   int presentNum=atoi(ptr[i]);
	   if(min>presentNum)
	    {
	     min=presentNum;
	    }
	   i++;
	}
	sleep(1);
        printf("\n the minimum value is :%d\n",min);
     }


      if(pthread_equal(id,tid[2]))
      {
         printf("\n processing third thread \n");
	 i=2;
	 while(i<num)
         {
	   int presentNum=atoi(ptr[i]);
	   if(min<presentNum)
	   {
             min=presentNum;
           }
           i++;
         }
        sleep(2);
        printf("\n the maximum value is :%d\n",min);
      }
   }
  /*Main Method*/
   int main(int argc, char *argv[] )
   {
	int i = 0;
	int err;
	ptr=argv;
	num=argc;
	/*While loop for creating pthreads. The loop ends when the pthread sequence touches 3*/
	while(i < 3)
	{
	  err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
	  i++;
        }
        sleep(6);
        return 0;
    }
