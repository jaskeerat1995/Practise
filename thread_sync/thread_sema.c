#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
	
void *thread_open(void *);
void *thread_read(void *);
void *thread_write(void *);
	
pthread_t threadID[5];
char text[BUFSIZ];
sem_t sema;
int fd, semid;
	
int main()
{	
	int threadFD, i = 0,k = 2, j = 1;
	char *rt;
	
	semid = sem_init(&sema,0,1);
	if (semid == -1)
	{
		perror("semid");
		exit(EXIT_FAILURE);
	}
	threadFD = pthread_create(&threadID[i],NULL,&thread_open,(void *)&i);		
	pthread_join(threadID[i],(void **)&rt);
	printf("exit code for open: %s\n",rt);
	
	//i++;
	threadFD = pthread_create(&threadID[j],NULL,&thread_read,(void *)&j);
	pthread_join(threadID[j],(void **)&rt);
	printf("exit code for read: %s\n",rt);
		
//	i++;
//	k = i;
	threadFD = pthread_create(&threadID[k],NULL,&thread_write,(void *)&k);
	pthread_join(threadID[k],(void **)&rt);
	printf("exit code for write: %s\n",rt);
			
	
	sem_destroy(&sema);
	
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
	
void *thread_read(void *arg)
{	
	int i;
	i = *(int *)arg;
	printf("thread_fd in thread_read function: %d\n",i);
	printf("Enter some text:\n");
	while(strncmp(text,"end",3) != 0)
	{
		sem_wait(&sema);
		fgets(text,BUFSIZ,stdin);
		printf("Input String: %s\n",text);
		sem_post(&sema);	
	}
	pthread_exit("thread_read: bye");	
}	
	
void *thread_write(void *arg)
{	
	int i, bytes;
	i = *(int *)arg;
	printf("thread_fd in thread_write function: %d\n",i);
	while(strncmp(text,"end",3) != 0)
	{
		sem_wait(&sema);
		bytes = write(fd,text,strlen(text));
		printf("bytes written = %d\n",bytes);
		sem_post(&sema);
	}
	pthread_exit("thread_write: bye");	
	
}	
