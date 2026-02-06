#include <stdio.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <string.h>

#define MAXTEXT 512

struct MarvellousMessage
{
    long int msg_type;
    char data[MAXTEXT];
};

int main()
{
    key_t key;
    key = ftok(".", 'a');

    int id = 0;
    struct MarvellousMessage mobj;
    int iRet = 0;

    id = msgget(key, 0666 | IPC_CREAT);
    if (id == -1)
    {
        printf("Unable to allocate msg Queue\n");
        return -1;
    }

    mobj.msg_type = 11;
    strcpy(mobj.data, "Gay Ganesh..");

    iRet = msgsnd(id, (void *)&mobj, sizeof(mobj.data), 0);
    if (iRet == -1)
    {
        perror("msgsnd failed");
        return -1;
    }

    printf("Message sent successfully\n");
    return 0;
}
