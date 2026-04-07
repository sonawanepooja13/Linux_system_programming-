#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
//myexe 11 21 
 int main()
 {
    setenv("LANGUAGE","C Programming",1); 
    printf("Language is %s\n",getenv("LANGUAGE")); 
    
    return 0; 
 }