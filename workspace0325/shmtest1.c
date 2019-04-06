#include <stdio.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/ipc.h> // remove warning
#include <sys/shm.h> // remove warning
#include <stdlib.h> // use perror

#define SEGSIZE 100

void removeshm(int shm_id)
{

	shmctl(shm_id, IPC_RMID, 0); // ipc delete
	printf("Shared memory segment marked for deletion\n");
}



int main()
{
	key_t key;
	int shm_id;
	key = ftok(".", 'a'); // "." is current directory
	//shmget(201524648,)
	//shm_id = shmget(key, SEGSIZE, IPC_CREAT | IPC_EXCL |0666); //exclusive, permission

	
	if((shm_id =
		 shmget(key, SEGSIZE, IPC_CREAT | IPC_EXCL |0666))==-1){
		printf("Shared memory segment exists - opening as client\n");
		// try as a client
		if((shm_id = shmget(key, SEGSIZE,0))==-1){
			perror("shmget error!!");
			exit(0);	
		}

	}

	return 0;

}
