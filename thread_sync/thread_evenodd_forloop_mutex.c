#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
	
void *thread_open(void *);
void *thread_even(void *);
void *thread_odd(void *);
	
pthread_t threadID[5];
pthread_mutex_t mutex1, mutex2;
int fd, ret;
	
int main()
{	
	int threadFD, i = 0,k = 2, j = 1;
	char *rt;

        ret = pthread_mutex_init(&mutex1, NULL);
        ret = pthread_mutex_init(&mutex2, NULL);
        if (ret != 0){
                perror("MUTEX Initialization failed");
                exit(EXIT_FAILURE);
        }
	
	threadFD = pthread_create(&threadID[i],NULL,&thread_open,(void *)&i);		
	pthread_join(threadID[i],(void **)&rt);
	printf("exit code for open: %s\n",rt);
	
//	i++;
//	while(1)
//	{

	threadFD = pthread_create(&threadID[k],NULL,&thread_odd,(void *)&k);
	pthread_join(threadID[k],(void **)&rt);
	printf("exit code for odd: %s\n",rt);

	threadFD = pthread_create(&threadID[j],NULL,&thread_even,(void *)&j);
	pthread_join(threadID[j],(void **)&rt);
	printf("exit code for even: %s\n",rt);
		
//	i++;
//	k = i;
			
//	}
	
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
	//pthread_mutex_lock(&mutex);
	for(val = 0; val <= 10; val += 2){
		pthread_mutex_unlock(&mutex1);
		printf("even val: %d\n",val);
		sleep(1);
		pthread_mutex_lock(&mutex2);
		sleep(1);
	}
		sleep(1);
	//pthread_mutex_unlock(&mutex);
	pthread_exit("thread_even: bye");	
}	
	
void *thread_odd(void *arg)
{	
	int i, val;
	i = *(int *)arg;
	printf("thread_fd in thread_odd function: %d\n",i);
	//pthread_mutex_lock(&mutex);
	for(val = 1; val <= 10; val += 2){
		pthread_mutex_unlock(&mutex2);
		printf("odd val: %d\n",val);
		sleep(1);
		pthread_mutex_lock(&mutex1);
		sleep(1);
	}
		sleep(1);
	//pthread_mutex_unlock(&mutex);
	pthread_exit("thread_odd: bye");	
	
}	
