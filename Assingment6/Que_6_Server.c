/*6. Write a program to demonstrate dynamic library search path resolution in Linux.
• Place a shared library in a custom directory.
• Write a client program that loads the library without specifying full path.
• Execute the program with and without setting LD_LIBRARY_PATH.
Explain the output in both cases.*/
#include <stdio.h>

void hello() {
    printf("Hello from shared library!\n");
}
