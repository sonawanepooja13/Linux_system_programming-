#include<stdio.h>
#include<pthread.h>
void *Demo(void*p)
{
    
    printf("Inside Thread\ with value :%d\n",*(int *)p); 
    return NULL; 

}
int main()
{
    pthread_t TID; 
    int iRet=0; 
    int Value=0; 
    int no=11; 
    printf("Main thread started\n"); 
    iRet=pthread_create(&TID,    //THread ID
                        NULL,   //thread attribute 
                        Demo,  //thread callbck function 
                        &no //parameter for callback function 
                    );
    if(iRet==0)
    {
         printf("thread created sucessfully with  TID :%lu\n",(unsigned long)TID); 
    }

    //wait 
    pthread_join(TID,NULL); 
  
    printf("end of thread\n"); 
     return 0; 

}