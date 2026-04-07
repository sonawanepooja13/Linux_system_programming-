#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
//myexe 11 21 
 int main()
 {
   FILE * fp = NULL; 
   char buffer[256]; 
   fp=fopen("/proc/meminfo","r"); 
   if(fp==NULL)
   {
       printf("UNable to open file\n"); 
       return -1; 
   }
   printf("-------------------------\n"); 
   printf("Marvellous Memory Scanner\n"); 
   printf("-------------------------\n"); 
   while(fgets(buffer,sizeof(buffer),fp)!=NULL)
   {
      printf("%s\n",buffer); 
      fclose(fp); 

   }
   printf("-------------------------\n"); 
    return 0; 
 }