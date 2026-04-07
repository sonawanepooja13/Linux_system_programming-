#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
//myexe 11 21 
 int main(int argc, char *argv[])
 {
   
    int Ans=0; 
    if(argc!=3)
    {
      printf("Invalid no of argument\n"); 
      return -1; 
    }
    Ans=atoi(argv[1])+atoi(argv[2]); 
    printf("ADdition is :%d\n",Ans); 
     
    return 0; 
    
 }