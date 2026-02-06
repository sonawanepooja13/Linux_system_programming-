#include<stdio.h>
#include<pthread.h>
void *Demo(void*p)
{
    int iSum=0;
    printf("Inside Thread with value\n ");
    //printf("%d\n",*(int *)(p+0)); 

    //iSum=*((int *)(p+0)+*(int *)(p+1)+*(int *)(p+2)+*(int *)(p+3));
    iSum = *((int *)p + 0) + *((int *)p + 1) + *((int *)p + 2) + *((int *)p + 3);

    //return iSum; 
    pthread_exit((int *)iSum); 

}
int main()
{
    pthread_t TID; 
    int iRet=0; 
    int Value=0; 
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
    printf(" iSum of THread %d\n",Value);
  
    printf("end of thread\n"); 
     return 0; 

}