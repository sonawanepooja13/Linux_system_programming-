#include<stdio.h>
#include<fcntl.h>
#include<dlfcn.h>
#include<stdlib.h>
int main()
{
    void *handle =NULL;
    int iRet=0; 
    int (*fp)(int, int); 

    handle=dlopen("./LIBClient1.so",RTLD_LAZY); 
    if(handle==NULL)
    {
        printf("Unable to load library\n"); 
        return -1; 
    }
    printf("Libraray get loaded sucessfully\n"); 
    fp=(int(*)(int, int))dlsym(handle,"Addition");
    if(fp==NULL)
    {
        printf("Unable to get Address of Function\n"); 
         dlclose(handle); 
         return -1; 
    }
    iRet=fp(11,10); 
    printf("Addition is %d\n",iRet); 


    fp=(int(*)(int, int))dlsym(handle,"SUbstarction");
    if(fp==NULL)
    {
        printf("Unable to get Address of Function\n"); 
         dlclose(handle); 
         return -1;
    }
    iRet=fp(11,10); 
    printf("Substraction is %d\n",iRet); 
    dlclose(handle); 
    return 0;
}

