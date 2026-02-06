/*
Accept a directory name fromm user and check a count 
 of capital letter and small letter inside it 
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<pthread.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>

char DirName[100];

void *CountCapital(void *p)
{
    DIR *dp;
    struct dirent *entry;
    struct stat sobj;
    char filepath[200];
    int fd, iRet, iCount = 0;
    char Buffer[1024];

    dp = opendir(DirName);
    if(dp == NULL)
    {
        perror("Unable to open directory");
        return NULL;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(filepath, "%s/%s", DirName, entry->d_name);
        stat(filepath, &sobj);

        if(S_ISREG(sobj.st_mode))   // Regular file
        {
            fd = open(filepath, O_RDONLY);
            if(fd == -1) continue;

            while((iRet = read(fd, Buffer, sizeof(Buffer))) > 0)
            {
                for(int i = 0; i < iRet; i++)
                {
                    if(Buffer[i] >= 'A' && Buffer[i] <= 'Z')
                        iCount++;
                }
            }
            close(fd);
        }
    }

    closedir(dp);
    printf("Number of CAPITAL letters: %d\n", iCount);
    return NULL;
}

void *CountSmall(void *p)
{
    DIR *dp;
    struct dirent *entry;
    struct stat sobj;
    char filepath[200];
    int fd, iRet, iCount = 0;
    char Buffer[1024];

    dp = opendir(DirName);
    if(dp == NULL)
    {
        perror("Unable to open directory");
        return NULL;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(filepath, "%s/%s", DirName, entry->d_name);
        stat(filepath, &sobj);

        if(S_ISREG(sobj.st_mode))
        {
            fd = open(filepath, O_RDONLY);
            if(fd == -1) continue;

            while((iRet = read(fd, Buffer, sizeof(Buffer))) > 0)
            {
                for(int i = 0; i < iRet; i++)
                {
                    if(Buffer[i] >= 'a' && Buffer[i] <= 'z')
                        iCount++;
                }
            }
            close(fd);
        }
    }

    closedir(dp);
    printf("Number of SMALL letters: %d\n", iCount);
    return NULL;
}

int main()
{
    pthread_t TID1, TID2;

    printf("Enter directory name: ");
    scanf("%s", DirName);

    pthread_create(&TID1, NULL, CountCapital, NULL);
    pthread_create(&TID2, NULL, CountSmall, NULL);

    pthread_join(TID1, NULL);
    pthread_join(TID2, NULL);

    return 0;
}
