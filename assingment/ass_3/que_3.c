/*
Move all file dir->dir 
accept a source dir and destination dir 
move all regualr file 
use rename if same filesytem 
else  copy+delete 
print count of moved files 

*/

//code is in pending state 

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int main()
{
    char Src_file[100];
    char Des_file[100];
    int src_fd, dest_fd;
    intbytes;
    char buffer[BUFFER_SIZE];
    struct stat st;

    printf("Enter source file: ");
    scanf("%s", Src_file);

    printf("Enter destination file: ");
    scanf("%s", Des_file);

    // Open source file
    src_fd = open(Src_file, O_RDONLY);
    if (src_fd == -1)
    {
        perror("Error opening source file");
        return 1;
    }
return 0; 

}
