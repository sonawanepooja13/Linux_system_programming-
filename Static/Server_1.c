#include<stdio.h>
//rcs repalce craete symbol index 
//ar archiile utility 
int Addition(int A,int B); 
int SUbstraction(int A, int B); 

int main()
{
    int iRet=0; 
    iRet=Addition(11,10); 
    printf("Addition is :%d",iRet); 

    iRet=SUbstraction(11,10); 
    printf("Addition is :%d",iRet); 

    
    return 0; 

}