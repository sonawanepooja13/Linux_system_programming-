#include<stdio.h>
int main(int argc, char *argv[])
{

     int i=0; 
     printf("Inside command line process\n"); 
     printf("command line argument is:"); 
     for(i=0;i<argc;i++)
     {
 printf("%s\n",argv[i]); 
     }
    // printf("GAY Ganesh\n"); 
     return 0; 
     
}