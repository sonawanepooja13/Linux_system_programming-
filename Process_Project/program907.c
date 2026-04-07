#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
//myexe 11 21 
 int main(int argc, char *argv[],char *envp[])
 {
  printf("List of Enviroment variable are :\n"); 
  int i=0; 
  for(i=0;envp[i]!=NULL;i++)
  {
    printf("%s\n",envp[i]); 
    
  }
  return 0; 
 }