/*
copy file content  from source to destination 
accept source_file to dest_file
create a destination if not exits (O_CREAT | O_TRUNC) 
copy using read/write() using loop 
preserve permissions (optional bonous using stat()+chmod())

read content using src file and write content in destination file 
*/
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

    // Get source file permissions (bonus)
    stat(Src_file, &st);

    dest_fd = open(Des_file, O_WRONLY | O_CREAT | O_TRUNC, st.st_mode);
    if (dest_fd == -1)
    {
        perror("Error opening destination file");
        close(src_fd);
        return 1;
    }
    // Copy data using read/write loop
    while ((bytes = read(src_fd, buffer, BUFFER_SIZE)) > 0)
    {
        write(dest_fd, buffer, bytes);
    }

    if (bytes == -1)
    {
        perror("Error reading file");
    }

    close(src_fd);
    close(dest_fd);

    printf("File copied successfully.\n");
    return 0;
}
