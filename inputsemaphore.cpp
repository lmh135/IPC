#include <sys/types.h>   
#include <sys/ipc.h>   
#include <sys/shm.h>   
#include <stdio.h>   
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "shm.h"
#define BUF_SIZE 1024   
 
int main()  
{ 
        int shmid;  
        char *shmptr;
	int val_data,val_place;

	if((val_data = semget(ftok("val_data",0),1,IPC_CREAT|0660)) == -1)
	{
		printf("semget val_data failed.");
		exit(1);
	}
	init_a_semaphore(val_data,0,0);

	if((val_place = semget(ftok("val_place",0),1,IPC_CREAT|0660)) == -1)
	{
		printf("semget val_place failed.");
		exit(1);
	}
	init_a_semaphore(val_place,0,1);	
	
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
	 semaphore_P(val_place);   	
 	 scanf("%s",shmptr);
	 semaphore_V(val_data); 
    }  
  
    exit(0);  
} 
