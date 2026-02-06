
//accept it through parameter 
// accept it through cmd line 
//join la pathva 
// lock file madh etaka 
//make file banva tyatun run kara 

//ek directory dya ani tyatil capital latter 


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<pthread.h>
void *Demo(void*p)
{
    
  int fd=0; 
  int iRet=0, iCount=0,i=0; 
  char Buffer[1024]={'\0'}; 
  fd=open("PPA.txt",O_RDONLY); 
  while((iRet=read(fd,Buffer,sizeof(Buffer)))!=0)
  {
     for(i=0;i<iRet;i++)
     {
        if((Buffer[i]>='A')&&(Buffer[i]<='Z'))
        {
            iCount++; 
        }
     }
  }
  close(fd); 
  printf("NUmber of capatial letter:%d \n",iCount); 
  return NULL; 

}

void *Hello(void*p)
{
    
 int fd=0; 
  int iRet=0, iCount=0,i=0; 
  char Buffer[1024]={'\0'}; 
  fd=open("LB.txt",O_RDONLY); 
  while((iRet=read(fd,Buffer,sizeof(Buffer)))!=0)
  {
     for(i=0;i<iRet;i++)
     {
        if((Buffer[i]>='a')&&(Buffer[i]<='z'))
        {
            iCount++; 
        }
     }
  }
  close(fd); 
  printf("NUmber of Small  letter:%d\n",iCount); 
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