#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/types.h>

static int semaphore_P(void);
static int semaphore_V(void);
static int set_semvalue(void);
static int del_semaphore(void);
int delete_shmat(void);

struct shared_memory
{
        int temp;
};

