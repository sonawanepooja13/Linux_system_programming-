#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct
{
    int num;
    int result;
} ThreadData;

void *SumEvenFactor(void *arg)
{
    ThreadData *data = (ThreadData *)arg;
    int n = data->num, sum = 0;

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0 && i % 2 == 0)
        {
            sum += i;
        }
    }

    data->result = sum;
    return NULL;
}

void *SumOddFactor(void *arg)
{
    ThreadData *data = (ThreadData *)arg;
    int n = data->num, sum = 0;

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0 && i % 2 != 0)
        {
            sum += i;
        }
    }

    data->result = sum;
    return NULL;
}

int main()
{
    int n;
    printf("Enter a Number: ");
    scanf("%d", &n);

    pthread_t t1, t2;
    ThreadData evenData = {n, 0};
    ThreadData oddData  = {n, 0};

    pthread_create(&t1, NULL, SumEvenFactor, &evenData);
    pthread_create(&t2, NULL, SumOddFactor,  &oddData);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Sum of Even Factors: %d\n", evenData.result);
    printf("Sum of Odd Factors : %d\n", oddData.result);
    printf("Exit From main\n");

    return 0;
}
