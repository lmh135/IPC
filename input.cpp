#include <sys/types.h>   
#include <sys/ipc.h>   
#include <sys/shm.h>   
#include <stdio.h>   
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define BUF_SIZE 1024   
#define MYKEY 55555   
int main()  
{ 
        int shmid;  
        char *shmptr;  
	if((shmid = shmget((key_t)1023467,BUF_SIZE,IPC_CREAT|0660)) == -1)
	{
		printf("shmget point_data failed.");
		exit(1);
	}
	shmptr = (char*)shmat(shmid,0,0);  
	if(shmptr==(char*)-1)  
	{
		printf("shm shmat point_data  failed"); 
		exit(1);
	}
  
    while(1)  
    {  
   	 printf("input:");  
   	 scanf("%s",shmptr);  
    }  
  
    exit(0);  
} 
