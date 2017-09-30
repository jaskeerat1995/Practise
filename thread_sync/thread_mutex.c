#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>

void *thread_function(void *arg);
pthread_mutex_t mutex;
char buffer[BUFSIZ];
int exit_flag = 1;

int main()
{
	int ret;
	pthread_t thread;
	char *return_code;
		
	ret = pthread_mutex_init(&mutex, NULL);
	if (ret != 0){
		perror("MUTEX Initialization failed");
		exit(EXIT_FAILURE);
	}

	ret = pthread_create(&thread, NULL, thread_function, NULL);
	if (ret != 0){
		perror("Thread Creation failed");
		exit(EXIT_FAILURE);
	}
	ret = pthread_join(thread, (void **)&return_code);
	if (ret != 0){
		perror("Thread Joined failed");
		exit(EXIT_FAILURE);
	}
	printf("%s\n",return_code);
	
	pthread_mutex_lock(&mutex);
	printf("Enter some text...! Press 'end' to exit\n");
	while(!exit_flag){
		fgets(buffer, BUFSIZ, stdin);
		pthread_mutex_unlock(&mutex);
		while(1){
			pthread_mutex_lock(&mutex);
			printf("fess geya\n");
			if (buffer[0] != '\0') {
			pthread_mutex_unlock(&mutex);
			sleep(1);
			}
			else {
				break;
			}
		}		
	}
	pthread_mutex_unlock(&mutex);
	
	pthread_mutex_destroy(&mutex);
	exit(EXIT_SUCCESS);
}

void *thread_function(void *arg)
{
	sleep(1);
	pthread_mutex_lock(&mutex);
	if(buffer[0] != '\0'){
	while(strncmp("end", buffer, 3) != 0){
		printf("You input %ld character\n",strlen(buffer) - 1);
		memset(buffer,'\0',sizeof(buffer));
		pthread_mutex_unlock(&mutex);
		sleep(1);
		pthread_mutex_lock(&mutex);
/*		while(buffer[0] == '\0'){
		   pthread_mutex_unlock(&mutex);
		   printf("in loop\n");
		   sleep(1);
		   pthread_mutex_lock(&mutex);
		}
*/	
	}
	}
	exit_flag = 0;
	memset(buffer,'\0',sizeof(buffer));
	pthread_mutex_unlock(&mutex);
	pthread_exit("out from thread_function");
}


