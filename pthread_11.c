#include<stdio.h>
#include<pthread.h>
void *Demo(void*p)
{
    
   printf("Inside  Demo Thread\n"); 
   return NULL; 

}

void *Hello(void*p)
{
    
   printf("Inside  Hello Thread\n"); 
   return NULL; 

}
int main()
{
    pthread_t TID1; 
    pthread_t TID2; 
    int iRet=0; 
    printf("Main thread started\n"); 
    iRet=pthread_create(&TID1,    //THread ID
                        NULL,   //thread attribute 
                        Demo,  //thread callbck function 
                        NULL  //parameter for callback function 
                    );
    if(iRet==0)
    {
         printf("thread created sucessfully with  TID1 :%lu\n",(unsigned long)TID1); 
    }



    iRet=pthread_create(&TID2,    //THread ID
                        NULL,   //thread attribute 
                        Hello,  //thread callbck function 
                        NULL  //parameter for callback function 
                    );
    if(iRet==0)
    {
         printf("thread created sucessfully with  TID :%lu\n",(unsigned long)TID2); 
    }

    //wait 
    pthread_join(TID1,NULL); 
    pthread_join(TID2,NULL); 

    printf("end of thread\n"); 
    return 0; 

}