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
    printf("Executable Name :%s\n",argv[0]); 
    printf(" IP Address :%s\n",argv[1]); 
    printf(" Port Number :%s\n",argv[2]); 
    printf(" Targeted file :%s\n",argv[3]);  //tithun magvaychi 
    printf(" New File Name : %s\n",argv[4]); 
    

    return 0; 

}