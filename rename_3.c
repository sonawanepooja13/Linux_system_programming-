#include<stdio.h>
#include<string.h>
#include<errno.h>

int main()
{ 
    int iRet=0; 
    iRet=rename("december.txt","./Test/Hello.txt"); 
    if(iRet==0)
    {
         printf("Rename sucessful\n"); 

    }
    else
    {
        printf("%s\n",strerror(errno));  
        return -1; 


    }
    
    
    return 0; 
} 