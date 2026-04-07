/*
Accept a file name from user
check filename inside directory
if present print filename
if not present print message

argv[0]     argv[1]    argv[2]
./findx      directory  Namefile.txt
argc = 3
*/

#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>

// Function to search file
void FindFile(char *dirname , char *filename)
{
    DIR *dp = NULL;
    struct dirent *entry;
    struct stat sobj;
    char path[1024];

    // open directory
    dp = opendir(dirname);
    if(dp == NULL)
    {
        printf("Unable to open directory : %s\n", dirname);
        return;
    }

    while((entry = readdir(dp)) != NULL)
    {
        // skip . and ..
        if(strcmp(entry->d_name,".") == 0 ||
           strcmp(entry->d_name,"..") == 0)
        {
            continue;
        }

        // create full path
        sprintf(path,"%s/%s",dirname,entry->d_name);

        // check file match
        if(strcmp(entry->d_name,filename) == 0)
        {
            printf("File Found : %s\n", path);
        }

        // get file information
        stat(path,&sobj);

        // if directory -> recursive call
        if(S_ISDIR(sobj.st_mode))
        {
            FindFile(path,filename);
        }
        
    }
    closedir(dp);
}
int main(int argc,char *argv[])
{
    if(argc != 3)
    {
        printf("Error: Insufficient Argument\n");
        printf("Usage: ./findx DirectoryName Filename\n");
        return -1;
    }

    FindFile(argv[1],argv[2]);

    return 0;
}