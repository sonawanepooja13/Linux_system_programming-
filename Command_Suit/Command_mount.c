
/*
START

Accept device name and mount directory
   from command line.
Check user permission (must be root user).
Verify device file exists.
Verify user access permission.
Verify mount directory exists.
call mount() system call.
Display success or error message.
STOP
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/mount.h>
#include<errno.h>

int main(int argc, char *argv[])
{
    struct stat st;

    // Step 1: Accept arguments
    if(argc != 3)
    {
        printf("Usage: %s <device> <mount_directory>\n", argv[0]);
        exit(1);
    }

    // Step 2: Check root permission
    if(geteuid() != 0)
    {
        printf("Error: Only root user can perform mount operation\n");
        exit(1);
    }

    // Step 3: Verify device file exists
    if(stat(argv[1], &st) != 0)
    {
        perror("Device file not found");
        exit(1);
    }

    // Step 4: Verify user access permission
    if(access(argv[1], R_OK) != 0)
    {
        perror("No permission to access device");
        exit(1);
    }

    // Step 5: Verify mount directory exists
    if(stat(argv[2], &st) != 0 || !S_ISDIR(st.st_mode))
    {
        printf("Mount directory does not exist\n");
        exit(1);
    }

    // Step 6: Call mount() system call
    if(mount(argv[1], argv[2], "ext4", 0, NULL) != 0)
    {
        perror("Mount failed");
        exit(1);
    }

    // Step 7: Success message
    printf("Filesystem mounted successfully!\n");

    return 0;
}