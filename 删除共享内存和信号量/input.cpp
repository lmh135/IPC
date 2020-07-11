#include <sys/types.h>   
#include <sys/ipc.h>   
#include <sys/shm.h>   
#include <stdio.h>   
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define BUF_SIZE 1024   

int main()  
{ 
        int shmid;  
        char *shmptr;  
	if((shmid = shmget((key_t)1023467,BUF_SIZE,IPC_CREAT|0660)) == -1)//创建共享内存
	{
		printf("shm creat failed!\n");
		exit(1);
	}
	shmptr = (char*)shmat(shmid,0,0);  //将共享内存链接到当前进程的地址空间
	if(shmptr==(char*)-1)  
	{
		printf("shmat failed!\n"); 
		exit(1);
	}
   
   	printf("input:");  
   	scanf("%s",shmptr);  
	
	if(shmdt(shmptr)==-1)//把共享内存从当前进程分离
	{
		printf("shmdt failed!\n");
		exit(1);	
	}
	
	if(shmctl(shmid,IPC_RMID,0)==-1)//删除共享内存
	{
		printf("rmid(delete) failed!\n");
		exit(1);
	}  		

    	exit(0);  
} 
