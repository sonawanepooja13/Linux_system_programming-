/*7. Create a shared library that maintains a global variable inside the library.
The library should provide functions to:
• Modify the global variable
• Display its value
• Reset its value
Write a dynamically linked client program to demonstrate persistence of the global variable across multiple function call */
/* mathlib.c 
mathlib.h
client.c 

...to run code
gcc -fPIC -c mathlib.c
gcc -shared -o libmath.so mathlib.o

gcc client.c -L. -lmath -o client

./client

*/ 
//this library is used to keep inside a global variable 
#include<stdio.h>
#include "mathlib.h"

int global_var=0;

void modify(int val)
{
    global_var=global_var+val; 
}

void display()
{
    printf("Global Varaible value :%d\n",global_var); 

}
void reset()
{
    global_var=0; 
}
