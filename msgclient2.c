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

    id = msgget(key, 0666);
    if (id == -1)
    {
        printf("Unable to allocate msg Queue\n");
        return -1;
    }
    //received letter logic 
    iRet=msgrcv(id,(void*)&mobj,MAXTEXT,11,IPC_NOWAIT); //msg type and flag 
    if(iRet >0)
    {
         printf("Data Received from message %s",mobj.data);
    }

}
