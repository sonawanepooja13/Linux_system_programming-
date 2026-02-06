#include<stdio.h>
#include<errno.h>
#include<unistd.h>
int main()
{
   printf(" current directire %s\n",getcwd()); //error in that file 
    return 0; 
}
