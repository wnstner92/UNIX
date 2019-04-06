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
	int i, j;
	SHM_INFOS *shm_info= NULL;
	void *shared_memory = (void *)0;


	// 공유메모리 공간을 만든다.
	shmid = shmget((key_t)3836, sizeof(SHM_INFOS)*SHM_INFO_COUNT, 0666|IPC_CREAT);

	if (shmid == -1)
	{
		perror("shmget failed : ");
		exit(0);
	}

	// 공유메모리를 사용하기 위해 프로세스메모리에 붙인다. 
	shared_memory = shmat(shmid, (void *)0, 0);
	if (shared_memory == (void *)-1)
	{
		perror("shmat failed : ");
		exit(0);
	}

	shm_info = (SHM_INFOS *)shared_memory;

    j = 100;

	while(1)
	{
		for(i=0 ;i < SHM_INFO_COUNT; i++){
			snprintf(shm_info[i].str_ip,sizeof(shm_info[i].str_ip),"1.1.1.%d",j);
			shm_info[i].int_ip =  j * -1;
			shm_info[i].int_id =  j;
            printf("Press Enter Key: "); 
            getchar();
            j++;
		}
	}
}
