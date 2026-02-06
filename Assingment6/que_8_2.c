#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    char str[100]; 
    printf("Enter a string:"); 
    scanf("%s",str); 

    size_t len=0; 
    while(str[len]!='\0')len++; 
    if(str[len-1]=='\n')str[len-1]='\0';


    //load to shared memory 
    void *handle=dlopen("./que_8.c",RTLD_LAZY); 
    if(!handle)
    {
        printf("error loading library :%s\n",dlerror()); 
        return 1; 
    }

    int(*count_lowercase)(const char *); 
    int(*count_uppercase)(const char *); 
    int(*count_digits)(const char *); 

    //to load a function from library 
    count_lowercase=dlsym(handle,"count_lowercase"); 
    count_uppercase=dlsym(handle,"count_uppercase"); 
    count_digits=dlsym(handle,"count_digits"); 

    char *error; 
    if((error=dlerror())!=NULL)
    {
          printf("error handling symbol :%s",error); 
          dlclose(handle); 
          return 1; 
    }

    printf("Lower case letter :%d\n",count_lowercase(str)); 
    printf("Upper case letter :%d\n",count_uppercase(str)); 
    printf("Digits %d\n",count_digits(str)); 

    dlclose(handle); 
}