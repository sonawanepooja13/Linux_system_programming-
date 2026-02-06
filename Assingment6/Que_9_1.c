/*9. Write a program to demonstrate the use of function pointers with dlsym().
• Store addresses of multiple dynamically loaded functions in an array of function pointers.
• Invoke functions using this array.
• Display function addresses along with results.*/

// to run code command is used 
//gcc -fPIC -shared -o libmylib.so mylib.c
//gcc -o main main.c -ldl
//./main

#include<stdio.h>
#include<stdlib.h>


int Addition(int A, int B)
{
     return A+B; 

}
int Substraction(int A, int B)
{
     return A-B; 
}