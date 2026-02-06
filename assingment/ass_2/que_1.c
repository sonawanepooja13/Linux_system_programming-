/*
read a whole file 
accept a filename and print whole content on console 
use buffer loop (read() until 0)
show total bytes read */


 #include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main()
{
    char filename[100];
    char buffer[1024];
    int fd;
    ssize_t bytesRead;
    int totalBytes = 0;

    printf("Enter a file which you want to open:\n");
    scanf("%s", filename);

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        printf("Unable to open file:\n");
        printf("%s\n", strerror(errno));
        return 1;
    }

    /* Read file using buffer loop */
    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0)
    {
        write(STDOUT_FILENO, buffer, bytesRead);
        totalBytes += bytesRead;
    }

    if (bytesRead == -1)
    {
        printf("\nError while reading file:\n");
        printf("%s\n", strerror(errno));
    }

    printf("\n\nTotal bytes read: %d\n", totalBytes);

    close(fd);
    return 0;
}
