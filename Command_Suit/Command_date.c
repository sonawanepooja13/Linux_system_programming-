#include <stdio.h>
#include <time.h>
//////////////////////////////////////////////////////////////////////////
// Self implement date command
/*
Algorithm:
1. Check argument count (should be 1).
2. Get current system time using time().
3. Convert to local time using localtime().
4. Format time using strftime().
5. Print formatted date.
*/
////////////////////////////////////////////////////////////
int main(int argc, char *argv[]) 
{
    time_t current_time;
    struct tm *local_time;
    char buffer[100];

    // date command does not take filename
    if (argc != 1)
    {
        printf("Error: No arguments required\n");
        printf("Usage: datex\n");
        return -1;
    }
    // Get current time
    time(&current_time);

    // Convert to local time
    local_time = localtime(&current_time);

    // Format output (same as default date)
    strftime(buffer, sizeof(buffer),
             "%a %b %d %H:%M:%S %Z %Y",
             local_time);

    // Print date
    printf("%s\n", buffer);

    return 0;
}
