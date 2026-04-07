#include<stdio.h>
int main(int argc, char *argv[])
{
    printf("No of command liane argument :%d\n", argc); 

    if(argc!=5)
    {
        printf("Unable to proceed to invalid argument\n"); 
        printf("Please provide\n"); 
        printf("IP Address\n Port NUmber \n Targeted file name\n new file name\n"); 
        return -1; 
    }
    int i=0;
    for(i=0;i<argc;i++)
    {
      printf("%s\n",argv[i]); 
    }

    return 0; 

}