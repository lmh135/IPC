#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;
#define BUF_SIZE 1024

int main()
{

    int shmid;
    char * shmptr;
    if((shmid = shmget((key_t)1023467,BUF_SIZE,IPC_CREAT|0660)) ==-1)
    {
        printf("shmget error!\n");
        exit(1);
    }
    if((shmptr = (char*)shmat(shmid,0,0)) == (char *)-1)
    {
        printf("shmat error!\n");
        exit(1);
    }
    while(1)
    {
        printf("string :%s\n",shmptr);
        sleep(3);
    }
    exit(0);
}
