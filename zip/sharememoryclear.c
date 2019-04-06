#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <string.h> 
#include <unistd.h>  
#include "share_memory.h"

int main()
{
	int shmid;

	// 공유메모리 공간을 만든다.
	shmid = shmget((key_t)3836, sizeof(SHM_INFOS)*SHM_INFO_COUNT, 0666|IPC_CREAT);

	if (shmid == -1)
	{
		perror("shmget failed : ");
		exit(0);
	}

	if ( -1 == shmctl( shmid, IPC_RMID, 0))
	{
		printf( "Failed to delete shared memory\n");
		return -1;
	}
	else
	{
		printf( "Successfully delete shared memory\n");
	}
	return 0;

}