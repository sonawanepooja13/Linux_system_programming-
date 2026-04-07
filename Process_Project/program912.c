#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

//myexe 11 21 

void ShowprocessInformation(int pid)

{
    FILE * fp=NULL; 
    char line[80]; 
    char filename[100]; 
    sprintf(filename,"/proc/%d/status",pid); 
    printf("Accessing a file :%s\n",filename); 

    fp=fopen(filename,"r"); 
    if(fp==NULL)
    {
      printf("Unable to access system file\n"); 
      return; 

    }
     printf("-----------------------------------------------\n"); 
     printf("------------Process INformation-----------------\n"); 
      printf("-----------------------------------------------\n"); 





      while(fgets(line,sizeof(line),fp)!=NULL)
      {
         if(strncmp(line,"Name:",5)==0 ||
         strncmp(line,"Pid",4)==0 ||
         strncmp(line,"State:",6)==0 ||
         strncmp(line,"Threads:",8)==0
      
      
      )
         
         
         printf("%s\n",line); 
      }
   }
 int main()
 {
   int pid=0; 
   printf("-----------------------------------------------\n"); 
   printf("---------Marvelous process inspector------------\n"); 
   printf("-----------------------------------------------\n"); 
   printf("Enter the PID of process that you wnat to inspect\n"); 
   scanf("%d",&pid); 
   if(pid<0)
   {
      printf("inavlid process si d\n"); 
      return -1; 
   }
   ShowprocessInformation(pid); 

    return 0; 
 }