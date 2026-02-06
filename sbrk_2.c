
//brk stand for break 
//sbrk -->segment break 

#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{
    void *current_break=NULL; 
    void *new_break=NULL; 


    current_break=sbrk(0); 
    printf("current process break %p\n",current_break); 


    new_break=sbrk(100); 
    strcpy((char *)new_break,"Jay Ganesh .."); // 100 byte mdhi lihil condition 
    printf("Data From new Memory %s\n",(char*)new_break); 
    sbrk(-100); 

     return  0; 
}