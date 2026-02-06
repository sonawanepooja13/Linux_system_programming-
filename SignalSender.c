#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main()
{
    pid_t pid;

    printf("Enter PID of process:\n");
    scanf("%d", &pid);

    if (kill(pid, SIGUSR1) == -1)
    {
        perror("kill failed");
        return -1;
    }

    printf("Signal SIGUSR1 sent successfully\n");
    return 0;
}
