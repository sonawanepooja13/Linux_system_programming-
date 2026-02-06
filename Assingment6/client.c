#include<stdio.h>
#include "mathlib.h"

int main()
{
    display(); 
    modify(10); 
    display(); 


    modify(5); 
    display(); 

    reset(); 
    display(); 
    
    return 0; 

}