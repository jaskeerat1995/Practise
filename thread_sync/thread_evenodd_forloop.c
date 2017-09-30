#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
	
void *thread_open(void *);
void *thread_even(void *);
void *thread_odd(void *);
	
pthread_t threadID[5];
sem_t sema1, sema2;
int fd, semid;
	
int main()
{	
	int threadFD, i = 0,k = 2, j = 1;
	char *rt;
	
	semid = sem_init(&sema1,0,0);
	semid = sem_init(&sema2,0,1);
	if (semid == -1)
	{
		perror("semid");
		exit(EXIT_FAILURE);
	}
	threadFD = pthread_create(&threadID[i],NULL,&thread_open,(void *)&i);		
	pthread_join(threadID[i],(void **)&rt);
	printf("exit code for open: %s\n",rt);
	
//	while(1)
//	{

	threadFD = pthread_create(&threadID[j],NULL,&thread_even,(void *)&j);
	pthread_join(threadID[j],(void **)&rt);
	printf("exit code for even: %s\n",rt);
		
	threadFD = pthread_create(&threadID[k],NULL,&thread_odd,(void *)&k);
	pthread_join(threadID[k],(void **)&rt);
	printf("exit code for odd: %s\n",rt);
			
//	}
	sem_destroy(&sema1);
	sem_destroy(&sema2);
	
	return 0;
}	
	
void *thread_open(void *arg)
{	
	int i;
	i = *(int *)arg;
	printf("thread_fd in open function: %d\n",i);
	fd = open("thread_text.txt", O_RDWR|O_CREAT);	
	if (fd < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	printf("fd = %d\n",fd);
	pthread_exit("thread_open: bye");	
}	
	
void *thread_even(void *arg)
{	
	int i, val;
	i = *(int *)arg;
	printf("thread_fd in thread_even function: %d\n",i);
	for(val = 0; val <= 100; val += 2){
		sem_wait(&sema2);
		printf("even val: %d\n",val);
		sem_post(&sema1);	
		sleep(1);
	}
	pthread_exit("thread_even: bye");	
}	
	
void *thread_odd(void *arg)
{	
	int i, val;
	i = *(int *)arg;
	printf("thread_fd in thread_odd function: %d\n",i);
	for(val = 1; val <= 100; val += 2){
		sem_wait(&sema1);
		printf("odd val: %d\n",val);
		sem_post(&sema2);
		sleep(1);
	}
	pthread_exit("thread_odd: bye");	
	
}	
