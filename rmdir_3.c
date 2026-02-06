#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <dirent.h>

int main()
{
    DIR *dp = NULL;
    struct dirent *ptr = NULL;

    dp = opendir(".");   // open current directory
    if (dp == NULL)
    {
        printf("%s unable to open\n", strerror(errno));
        return -1;
    }

  

    while( ptr = readdir(dp))
   {
        //fd=open(ptr->d_name,O_RDONLY); 
        //iREt=read(fd,)

        
   }

    closedir(dp);
    return 0;
}
//assingment 2 ref 