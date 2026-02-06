#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *Demo(void*p)
{
    int iSum=0;
    int *ptr=NULL;
    ptr=(int *)malloc(sizeof(int));
    printf("Inside Thread with value\n ");
    iSum = *((int *)p + 0) + *((int *)p + 1) + *((int *)p + 2) + *((int *)p + 3);

    *ptr=iSum; 
    pthread_exit(ptr); 

}
int main()
{
    pthread_t TID; 
    int iRet=0; 
    int *Value=NULL; 
    int Arr[]={11,21,51,101}; 
    printf("Main thread started\n"); 
    iRet=pthread_create(&TID,    //THread ID
                        NULL,   //thread attribute 
                        Demo,  //thread callbck function 
                        (int *)Arr //parameter for callback function 
                    );
    if(iRet==0)
    {
         printf("thread created sucessfully with  TID :%lu\n",(unsigned long)TID); 
    }

    //wait 
    pthread_join(TID,&Value); 
    printf(" Summation is :%d\n",*Value);
  
    printf("end of thread\n"); 
     return 0; 

}