#include<stdio.h>
int Addition(int No1,int No2)
{
    int Ans=0; 
    Ans=No1+No2; 
    return Ans; 
}
int main()
{
    int Ret=0,a=0,b=0; 
    printf("Enter a first NUmber:\n"); 
    scanf("%d",&a); 
    printf("Enter a second number\n"); 
    scanf("%d",&b); 

    Ret=Addition(a,b); 
    printf("Addition of number: %d\n",Ret); 
}


///to run a code 
//gcc debug1.c -o myexe -g 
//run: gdb ./myexe 
//then gdb shell open able to give permission 
//quit is closed 
//again start 
//print a 
//run command aadd ,next 
 