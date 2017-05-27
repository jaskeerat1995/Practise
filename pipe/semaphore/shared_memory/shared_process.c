#include"header.h"

static int sem_id;

union semun
{
	int val;
};

int main()
{
	void *shared_pointer = (void *)0;
	struct shared_memory *shared_ptr;
	int shmid, i;
	char **p, child_pid[8];
	
	p = (char **)malloc(sizeof(char) * 30);	
	*(p + 0) = "./client1";
	*(p + 1) = "./client2";
	*(p + 2) = "./client3";
	
	pid_t pid;
	pid_t PID;
	
	
	sem_id = semget((key_t)1234, 1, 0666|IPC_CREAT);
	set_semvalue();
	
	shmid = shmget((key_t)123, sizeof(struct shared_memory), 0666|IPC_CREAT);
	if (shmid == -1){
		perror("shmget failed");
		exit(EXIT_FAILURE);
	}
	printf("%s : shmid = %d\n",__FILE__,shmid);

	shared_pointer = shmat(shmid, (void *)0, 0);
	if (shared_pointer == (void *)-1){
		perror("shmat failed");
		exit(EXIT_FAILURE);
	}
	
	printf("Memory attached at %X\n",(int *)shared_pointer);		
	
	shared_ptr = (struct shared_memory *)shared_pointer;

	for(i = 0; i < 3; i++)
	{
		pid = fork();
		switch(pid)
		{
			case -1: perror("fork failed");
				 goto OUT;
	
			case 0:  printf("This is child process");
				 PID = getpid();
				 sprintf(child_pid,"%d",PID);
				 execl(*(p + i),*(p + i),child_pid,NULL);
				 printf("execl failed\n");
		}
		printf("This is parent.....\n");
		printf("parent pid: %d\n",getpid());	
	}		
		
/*	
	if (shmdt(shared_pointer) == -1){
		perror("shmdt failed");
		exit(EXIT_FAILURE);
	}
	
	if(shmctl(shmid, IPC_RMID, 0) == -1){
		perror("shmdt failed");
		exit(EXIT_FAILURE);
	}
*/	

	//exit(EXIT_SUCCESS);
	return 0;
OUT:	return -1;
}

int delete_shmat(void)
{
	

}

static int set_semvalue(void)
{
	union semun sem_union;
	
	sem_union.val = 1;
	if (semctl(sem_id, 0, SETVAL, sem_union) == -1)
		return 0;

	
	return 1;
}

static int semaphore_P(void)     // This is "wait" operation
{
	struct sembuf sem_b;
	
	sem_b.sem_num = 0;
	sem_b.sem_op = -1;
	sem_b.sem_flg = SEM_UNDO;
	if (semop(sem_id, &sem_b, 1) == -1){
		perror("semop failed");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);	
}

static int semaphore_V(void)     // This is "release" operation
{
	struct sembuf sem_b;
	
	sem_b.sem_num = 0;
	sem_b.sem_op = 1;
	sem_b.sem_flg = SEM_UNDO;
	if (semop(sem_id, &sem_b, 1) == -1){
		perror("semop failed");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);	
}

static int del_semaphore(void)
{
	union semun sem_union;	

	if (semctl(sem_id, 0, IPC_RMID, sem_union) == -1){
		perror("Failed to delete semaphore");
		exit(EXIT_FAILURE);
	}

}
