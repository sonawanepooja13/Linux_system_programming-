/*
 write a string to File
 accept a filename and string from user
 write a string using write() (append mode)
 print number of bytes written
*/



#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
    char filename[100]; 
    char data[500];       
    int fd; 
    ssize_t Byte_Write;    

    printf("Enter a filename: "); 
    scanf("%s", filename);
    getchar();  // consume newline left by scanf

    printf("Enter string to write: ");
    fgets(data, sizeof(data), stdin);  // read string with spaces

    fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0644); 
    if (fd == -1)
    {
        perror("open"); 
        return 1; 
    }

    Byte_Write = write(fd, data, strlen(data)); 
    if (Byte_Write == -1)
    {
        perror("write"); 
        close(fd);
        return 1;
    }
    else
    {
        printf("Number of bytes written: %ld\n", Byte_Write);
    }

    close(fd);
    return 0; 
}
