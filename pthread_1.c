#include<stdio.h>
void Demo(int *p)
{
    *p=11; 
    
    
}
int main()
{

    int No=0; 
    Demo(&No); 
    printf("value of NO is:%d\n",No); 
     return 0; 

}