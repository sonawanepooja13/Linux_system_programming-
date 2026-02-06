#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<pthread.h>

void *Demo(void *p)
{
    char *filename = (char *)p;

    int fd = 0, iRet = 0, iCount = 0, i = 0;
    char Buffer[1024];

    fd = open(filename, O_RDONLY);
    if(fd == -1)
    {
        perror("Unable to open file");
        return NULL;
    }

    while((iRet = read(fd, Buffer, sizeof(Buffer))) > 0)
    {
        for(i = 0; i < iRet; i++)
        {
            if(Buffer[i] >= 'A' && Buffer[i] <= 'Z')
                iCount++;
        }
    }

    close(fd);
    printf("Number of CAPITAL letters in %s: %d\n", filename, iCount);
    return NULL;
}

void *Hello(void *p)
{
    char *filename = (char *)p;

    int fd = 0, iRet = 0, iCount = 0, i = 0;
    char Buffer[1024];

    fd = open(filename, O_RDONLY);
    if(fd == -1)
    {
        perror("Unable to open file");
        return NULL;
    }

    while((iRet = read(fd, Buffer, sizeof(Buffer))) > 0)
    {
        for(i = 0; i < iRet; i++)
        {
            if(Buffer[i] >= 'a' && Buffer[i] <= 'z')
                iCount++;
        }
    }

    close(fd);
    printf("Number of SMALL letters in %s: %d\n", filename, iCount);
    return NULL;
}

int main()
{
    pthread_t TID1, TID2;
    char File1[100], File2[100];

    printf("Enter first filename: ");
    scanf("%s", File1);

    printf("Enter second filename: ");
    scanf("%s", File2);

    printf("Main thread started\n");

    pthread_create(&TID1, NULL, Demo, File1);
    pthread_create(&TID2, NULL, Hello, File2);

    pthread_join(TID1, NULL);
    pthread_join(TID2, NULL);

    printf("End of thread\n");
    return 0;
}
