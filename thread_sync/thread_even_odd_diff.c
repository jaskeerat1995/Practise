#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>



void *thread_function_Even(void *arg);
void *thread_function_Odd(void *arg);
void *Read_Buff(void *arg);


int run_now = 1;
int i = 0;

sem_t bin_sem1;
sem_t bin_sem2;
#define BUF_SIZE 50

int Buffer[BUF_SIZE];
char message[] = "Hello World";

pthread_mutex_t work_mutex; 

int main(void)
{

	int res;
	pthread_t a_thread_even, b_thread_odd, read_thread;
	void *thread_result_even, *thread_result_odd, *read_buff_result;
	
	

	res = sem_init(&bin_sem1, 0, 0);
	if(res != 0){
		perror("Semaphore creation is failed\n");
		exit(EXIT_FAILURE);
	}

	res = sem_init(&bin_sem2, 0, 1);
	if(res != 0){
		perror("Semaphore creation is failed\n");
		exit(EXIT_FAILURE);
	}

	res = pthread_mutex_init(&work_mutex, NULL);
	if(res != 0){
		perror("Mutex creation is failed\n");
		exit(EXIT_FAILURE);
	}
	
	res = pthread_create(&a_thread_even, NULL, thread_function_Even, (void *)message);
	if(res != 0){
		perror("Thread creation is failed\n");
		exit(EXIT_FAILURE);
	}

//	res = pthread_create(&b_thread_odd, NULL, thread_function_Odd, (void *)message);
	printf("waiting for thread to finish............\n");

	res = pthread_create(&read_thread, NULL, Read_Buff, (void *)message);
	if(res != 0){
		perror("read_buff  Thread joined is failed\n");
		exit(EXIT_FAILURE);
	}
	
	res = pthread_join(a_thread_even, &thread_result_even);
	if(res != 0){
		perror("even  Thread joined is failed\n");
		exit(EXIT_FAILURE);
	}

	printf("%s\n",(char *)thread_result_even);	
	
//	res = pthread_join(b_thread_odd, &thread_result_odd);
	res = pthread_join(read_thread, &read_buff_result);
	if(res != 0){
		perror("read buff Thread joined is failed\n");
		exit(EXIT_FAILURE);
	}
	printf("%s\n",(char *)read_buff_result);	
	
	exit(EXIT_SUCCESS);
}

void *thread_function_Even(void *arg)
{
	int in=0;	
	
	for(i =0; i<10; i++){

		if(i%2 == 0){
			sem_wait(&bin_sem2);
			pthread_mutex_lock(&work_mutex);
			Buffer[in] = i;
			printf(" write on BUFF = %d\n",i);
			in  = (in +1)% BUF_SIZE ;			
			pthread_mutex_unlock(&work_mutex);
			sem_post(&bin_sem1);
		}
	}		
	
	pthread_exit("Even function is done \n");

}

void *Read_Buff(void *arg)
{
	int out=0, item;
	
	while(out != 5){
	sem_wait(&bin_sem1);
	pthread_mutex_lock(&work_mutex);
	item = Buffer[out];
	printf("reading is done %d\n",item);
	out = (out +1)%BUF_SIZE;
	pthread_mutex_unlock(&work_mutex);
	sem_post(&bin_sem2);
	}
	
	pthread_exit("reading done e\n"); 	
}

/*void *thread_function_Odd(void *arg)
{

	
	for(i =0; i<10; i++){
		sem_wait(&bin_sem1);	
		if(i%2 != 0){
			printf("odd=  %d\n ",i);
		}
		sem_post(&bin_sem2);		
	}
	
	
	pthread_exit("odd function is done\n"); 	

}
*/



	 
    


