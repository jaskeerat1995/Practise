/**************Header Files****************/

#include <stdio.h>
#include <pthread.h>
#include <fcntl.h>
#include<unistd.h>
#include <stdlib.h>
#include <string.h>

/*******************Global Variable**************/
int fd;
char text[10];
char buff[BUFSIZ];
pthread_t thrd[2];
pthread_attr_t tattr;

/*****************Function Prototype****************/
void open_func();
void thread_func_read();
void thread_func_write();
void *thread_read(void *);
void *thread_write(void *);

int main()
{
	open_func();		//Function to open file
	while(1){
		memset(text , '\0', sizeof(text));
		printf("enter -  read/write:\n");
		fgets(text, BUFSIZ, stdin);
		
		if(strncmp("end", text, 3) == 0){
			printf("why??\n");
			break;
		}
	
		if(strncmp("read", text, 4) == 0)
		{
		thread_func_read();		//Function to create thread
		}
		if(strncmp("write", text, 5) == 0)
		{
		thread_func_write();		//Function to create thread
		}
		//scanf("%m[a-z]", &text);

		sleep(1);
	}
	
	close(fd);


	return 0;

}

void open_func()
{
	fd = open("development_file.txt", O_RDWR | O_CREAT);
	printf("fd : %d\n",fd);
	if(fd == -1){
		perror("open");
		exit(EXIT_FAILURE);
	}
}

void thread_func_read()
{
	int i = 0;
	if(pthread_attr_init(&tattr)){
		perror("pthread_attr_init");
		exit(EXIT_FAILURE);
	}

	if(pthread_attr_setdetachstate(&tattr, PTHREAD_CREATE_DETACHED)){
		perror("pthread_attr_setdetachstate");
		exit(EXIT_FAILURE);
	}
	
	pthread_create(&thrd[0], &tattr, &thread_read, (void *)&i);
}

void thread_func_write()
{
	int i = 1;
	if(pthread_attr_init(&tattr)){
		perror("pthread_attr_init");
		exit(EXIT_FAILURE);
	}

	if(pthread_attr_setdetachstate(&tattr, PTHREAD_CREATE_DETACHED)){
		perror("pthread_attr_setdetachstate");
		exit(EXIT_FAILURE);
	}
	
	pthread_create(&thrd[1], &tattr, &thread_write, (void *)&i);
}

void *thread_read(void *num)
{
	int i = *(int *)num;
	int bytes;
		if(strncmp("read", text, 4) == 0){
			printf("i'm in the read thread\n");
			memset(text , '\0', sizeof(text));
			bytes = read(fd,buff,strlen(buff));
			printf("Bytes read: %d\n",bytes);
		}
}

void *thread_write(void *num)
{
	int i = *(int *)num;
	int bytes;
		if(strncmp("write", text, 5) == 0){
			printf("In write thread.......\n");
			memset(text , '\0', sizeof(text));
			printf("Enter data: \n");
			fgets(buff, BUFSIZ, stdin);
			bytes = write(fd,buff,strlen(buff));
			printf("Bytes written : %d\n",bytes);
		}

}

