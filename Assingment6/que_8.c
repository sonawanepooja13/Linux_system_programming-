/* Write a C program to dynamically load a shared library that performs string operations:
• Count number of lowercase letters
• Count number of uppercase letters
• Count number of digits
The client program should accept a string from the user and call the appropriate functions*/

//string_lib.c 
//dynmic_client.c

#include<stdio.h>
#include<ctype.h>


int count_lowercase(const char *str)
 {
    int count = 0;
    for (int i = 0; str[i]; i++)
        if (islower(str[i]))
            count++;
    return count;
}

int count_uppercase(const char *str)
 {
    int count = 0;
    for (int i = 0; str[i]; i++)
        if (isupper(str[i]))
            count++;
    return count;
}

int count_digits(const char *str)
 {
    int count = 0;
    for (int i = 0; str[i]; i++)
        if (isdigit(str[i]))
            count++;
    return count;
}

