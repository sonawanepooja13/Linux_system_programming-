#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
//myexe 11 21 
 int main()
 {
  printf(" Home Directory: %s\n",getenv("HOME"));  
  printf("Shell Used: %s\n",getenv("SHELL")); 
  return 0; 
 }