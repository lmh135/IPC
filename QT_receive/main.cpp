#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include "shm.h"
using namespace std;
#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int shmid;
    char * shmptr;
    //******************semaphore
    int val_data,val_place;
    if((val_data = semget(ftok("val_data",0),1,IPC_CREAT|0660)) == -1)
    {
    printf("semget val_data failed.");
    exit(1);
    }

    if((val_place = semget(ftok("val_place",0),1,IPC_CREAT|0660)) == -1)
    {
    printf("semget val_place failed.");
    exit(1);
    }
    //****************************
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
        cout<<"hello"<<endl;
        semaphore_P(val_place);   //semaphore
        printf("string :%s\n",shmptr);
        semaphore_V(val_data);
        sleep(0.3);
    }
    exit(0);
}
