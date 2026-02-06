
#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{
    void *current_break=NULL; 

    current_break=sbrk(0); 
    printf("current process break %p\n",current_break); 


    brk((char *)current_break+100); 
    strcpy((char *)current_break,"Jay Ganesh .."); // 100 byte mdhi lihil condition 
    printf("Data From new Memory %s\n",(char*)current_break); 
    sbrk(-100); 
     return  0; 
}