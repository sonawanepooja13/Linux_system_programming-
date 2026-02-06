
//brk stand for break 
//sbrk -->segment break 

#include<stdio.h>
#include<unistd.h>
int main()
{
    void *ptr=NULL; 
    ptr=sbrk(0); 
    printf("Current break value:%p\n",brk);
    *(char *)ptr='A';

     return  0; 
}