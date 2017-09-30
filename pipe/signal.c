#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<signal.h>

int flag = 0;

void sig(int s)
{
	flag = 1;
}

int main()
{
	pid_t pid;

	printf("program starts\n");	
	(void)signal(2,sig);	

	pid = fork();
	switch(pid){
	case -1: perror("fork failed");
		 goto OUT;
	case 0:  sleep(3);
		 kill(getppid(), 2);
		 break;
	}

	printf("parent process\n");
	pause();
	if(flag)
	{
		printf("catch the signal\n");
	}	
	
	
	return 0;
OUT: 	return -1;

}
