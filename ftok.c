

//ipc_privte 
#include<sys/ipc.h>
#include<stdio.h>
int main()
{
    key_t key; 
    key=ftok("Demo.txt",'m'); 
    printf("Key is :%d\n",key);
    

    return 0; 
}