#include<stdio.h>
#include<pthread.h>
void *Demo(void*p)
{
    
   printf("Inside Thread\n"); 
   return NULL; 

}
int main()
{
    pthread_t TID; 
    int iRet=0; 
    printf("Main thread started\n"); 
    iRet=pthread_create(&TID,    //THread ID
                        NULL,   //thread attribute 
                        Demo,  //thread callbck function 
                        NULL  //parameter for callback function 
                    );
    if(iRet==0)
    {
         printf("thread created sucessfully with  TID :%lu\n",(unsigned long)TID); 
    }

    //wait 
    pthread_join(TID,NULL); 

    printf("end of threa\n"); 
     return 0; 

}