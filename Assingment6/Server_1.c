// 1. Write a program to create a shared library (.so) that contains two functions:
// • Addition(int, int)
// • Substraction(int, int)
// Write a separate client program that loads this library at runtime using dlopen() and calls both functions using
// dlsym().

#include<stdio.h>
int Addition(int a, int b)
{
    return a+b; 
}
int Substraction(int a, int b)
{
     return a-b; 
}