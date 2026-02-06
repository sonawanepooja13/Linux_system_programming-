#include <stdio.h>
#include <pthread.h>

void *Even_Thread(void *arg)
{
    for (int i = 1; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            printf("Even Number: %d\n", i);
        }
    }
    return NULL;
}

void *Odd_Thread(void *arg)
{
  
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 1)
        {
            printf("Odd Number: %d\n", i);
        }
    }
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, Even_Thread, NULL);
    pthread_create(&t2, NULL, Odd_Thread, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Main: All Threads completed\n");

    return 0;
}
