#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<pwd.h>
#include<grp.h>
/*
Algorithm 
this command is used to print 
Real User  id ---> getuid
Real Group id 
username 
group name 
etc
*/

int main()
{
//to print a Real user id 
   uid_t uid=getuid(); 
   printf("Real User id :%d\n",uid); 
//to print real group id 
uid_t gid=getgid(); 
printf("Real Group id :%d\n",gid); 
//to priint user nam e
printf("Username :%s\n",getlogin()); 

   return 0; 
}

////////////////
//compile : gcc Command_id.c -o myexe
// ./myexe 
