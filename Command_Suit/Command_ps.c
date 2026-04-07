/*
PS: This is used to report snapshot of current processes.
process status 
Algorithm:

START
1. Open /proc directory.
2. Read all subdirectories.
3. Check directory name is integer (PID).
4. Open comm file inside that directory.
5. Read process name.
6. Display PID and process name.
7. Repeat for all entries.
8. Close directory.
STOP

argc = 1
argv[0] -> ./psx
*/

#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<ctype.h>
#include<string.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *entry;
    FILE *fp;
    char path[256];
    char pname[256];
    int i, flag;

    // argc check
    if(argc != 1)
    {
        printf("Usage: %s\n", argv[0]);
        exit(1);
    }

    // Step 1: Open /proc directory
    dp = opendir("/proc");
    if(dp == NULL)
    {
        perror("Unable to open /proc");
        exit(1);
    }

    printf("PID\tProcess Name\n");
    printf("---------------------------\n");

    // Step 2: Read entries
    while((entry = readdir(dp)) != NULL)
    {
        flag = 1;

        // Step 3: Check numeric directory
        for(i = 0; entry->d_name[i] != '\0'; i++)
        {
            if(!isdigit(entry->d_name[i]))
            {
                flag = 0;
                break;
            }
        }

        // Step 4: Open comm file
        if(flag)
        {
            sprintf(path, "/proc/%s/comm", entry->d_name);

            fp = fopen(path, "r");
            if(fp != NULL)
            {
                // Step 5: Read process name
                fgets(pname, sizeof(pname), fp);

                // Step 6: Display
                printf("%s\t%s", entry->d_name, pname);

                fclose(fp);
            }
        }
    }

    // Step 7: Close directory
    closedir(dp);

    return 0;
}