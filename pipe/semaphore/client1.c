#include"header.h"

static int sem_id;

union semun
{
	int val;
};

int main(int argc, char *argv[])
{
	long int pid;
	void *shared_pointer = (void *)0;
        struct shared_memory *shared_ptr;
	int shmid;
	
	pid = atoi(argv[1]);
	shmid = atoi(argv[2]);		
	printf("In %s: file: PID = %ld\n",__FILE__,pid);
	
	
	sem_id = semget((key_t)1234, 1, 0666|IPC_CREAT);
        set_semvalue();
	
 /*       shmid = shmget((key_t)123, sizeof(struct shared_memory), 0666|IPC_CREAT);
        if (shmid == -1){
                perror("shmget failed");
                exit(EXIT_FAILURE);
        }
*/
	printf("%s : shmid = %d\n",__FILE__,shmid);

        shared_pointer = shmat(shmid, (void *)0, 0);
        if (shared_pointer == (void *)-1){
                perror("shmat failed");
                exit(EXIT_FAILURE);
        }
	
        printf("%s : memory attached at %X\n",__FILE__,(int *)shared_pointer);
	
        shared_ptr = (struct shared_memory *)shared_pointer;
	
	semaphore_P();
	shared_ptr->temp = shared_ptr->temp + 1;
	printf("value present in shared memory: %d\n",shared_ptr->temp);
	semaphore_V();

/* 	                                       // no need to delete
	if (shmdt(shared_pointer) == -1){
                perror("shmdt failed");
                exit(EXIT_FAILURE);
        }

        if(shmctl(shmid, IPC_RMID, 0) == -1){
                perror("shmdt failed");
                exit(EXIT_FAILURE);
        }
*/	
	
	return 0;
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
	printf("wait....\n");
        sem_b.sem_num = 0;
        sem_b.sem_op = -1;
        sem_b.sem_flg = SEM_UNDO;
        if (semop(sem_id, &sem_b, 1) == -1){
                perror("semop failed");
                //exit(EXIT_FAILURE);  //wrong one
		//return 0;
		goto OUT;
        }

       // exit(EXIT_SUCCESS);   // wrong
//	return(1);   // correct "working"

	return 0;
OUT:	return -1;
}
	
static int semaphore_V(void)     // This is "release" operation
{
        struct sembuf sem_b;
	printf("release...\n");
        sem_b.sem_num = 0;
        sem_b.sem_op = 1;
        sem_b.sem_flg = SEM_UNDO;
        if (semop(sem_id, &sem_b, 1) == -1){
                perror("semop failed");
               // exit(EXIT_FAILURE);
	//	return 0;
		goto OUT;
        }

       // exit(EXIT_SUCCESS);
//	return(1);
	return 0;
OUT:	return -1;
}

static int del_semaphore(void)
{
        union semun sem_union;

        if (semctl(sem_id, 0, IPC_RMID, sem_union) == -1)
                perror("Failed to delete semaphore");

}

