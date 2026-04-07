#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

void getsectiontType(char *details,char *perms,char *section)
{
   if(strcmp(details,"[heap]")==0)
   {
      strcpy(section,"HEAP"); 

   }

   else if(strcmp(details,"[stack]")==0)
   {
      strcpy(section,"STACK"); 
      
   }

  else  if(strcmp(details,"[vdso]")==0)
   {
      strcpy(section,"VDSO"); 
      
   }
 else  if(strcmp(details,"[vvar]")==0)
   {
      strcpy(section,"VVAR"); 
      
   }
   else if(perms[2]=='x')
   {
      strcpy(section,"TEXT");   
   }
   else if(perms[2]=='w')
   {
      strcpy(section,"DATA"); 
      
   }
   else
   {
      strcpy(section,"OTHER"); 
      
   }

}
void ShowMemoryLayout(int pid)
{
    FILE * fp=NULL; 
    char line[80]; 
    char filename[100]; 
    sprintf(filename,"/proc/%d/maps",pid); 
    printf("Accessing a file :%s\n",filename); 

    fp=fopen(filename,"r"); 
    if(fp==NULL)
    {
      printf("Unable to access system file\n"); 
      return; 

    }
     printf("-----------------------------------------------\n"); 
     printf("------------Memory Layout ---------------------\n"); 
      printf("-----------------------------------------------\n"); 
      printf("-----------Header..............................\n"); 

      while(fgets(line,sizeof(line),fp)!=NULL)
      {
         char address[100],perms[10],offset[20],dev[20],details[300]="";
         unsigned long inode; 
         unsigned long start,end; 
         unsigned long sizekb; 
         char section[50]; 
         int ret=0; 
         ret=sscanf(line,"%s %s %s %s %lu %[^\n]",address,perms,offset,dev,&inode,details); 
         if(ret>=5)
         {
            sscanf(address,"%lx-%lx",&start,&end); 
            sizekb=(end-start)/1024; 

            getsectiontType(details,perms,section); 
            if(strlen(details)==0)
            {
               strcpy(details,"Anonymous"); 
            }
            printf("%lx %lx %lu %s %s %s\n",start,end,sizekb,perms,section,details);
         }
      }
   fclose(fp);


}
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
   ShowMemoryLayout(pid);

    return 0; 
 }
 /*
 exepected section 
 text section /code (binary instruction code)

 data  (global veriable )
 stack 
 VDSO (virtual dynamic shared object )
 VVAR (virtual variables )
 VSYSCALL(virtial system cll page)
 other memory region 
 */
 /*
 explanatuion: 

 process cha ek code 904 running state: 
 two function process status memory info 
 add features user je vichrel tech dispaly kara 

 /proc/status 
 ananlogous entry of process table 
 sved nahi simiiar (analogous)
 
 
 */
