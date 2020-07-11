#include <stdio.h>  
#include <unistd.h>  //getpagesize(  )  
#include <sys/ipc.h>  
#include <sys/shm.h>  
#define MY_SHM_ID 67483  

int main()
{
	printf("page size=%d/n",getpagesize());
	int shmid,ret;
	if((shmid=shmget(MY_SHM_ID,4096,0666|IPC_CREAT ))==-1)
	{
		printf("shmget point_data failed.");
		return -1;
	}  
 	printf( "Create a shared memory segment %d/n",shmid );  
 	struct shmid_ds shmds;  
 	ret=shmctl( shmid,IPC_STAT,&shmds );  
        if( ret==0 )  
            {  
                printf( "Size of memory segment is %d/n",shmds.shm_segsz );  
                printf( "Numbre of attaches %d/n",( int )shmds.shm_nattch );  
            }  
        else  
            {  
                printf( "shmctl(  ) call failed/n" );  
            }  
        //删除该共享内存区  
        ret=shmctl( shmid,IPC_RMID,0 );  
        if( ret==0 )  
            printf( "Shared memory removed /n" );  
        else  
            printf( "Shared memory remove failed /n" );  
	return 0;
}
