// echo :- Hello world 
//argc : 1
//argv[0] argv[1] ---> ./echox hello world 
#include<stdio.h>

int main(int argc, char *argv[])
{
    int i;

    for(i = 1; i < argc; i++)   // start from 1
    {
        printf("%s ", argv[i]);
    }

    printf("\n");

    return 0;
}
