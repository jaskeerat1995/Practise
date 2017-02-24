#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>



int main()
{

	pid_t pid;
	printf("%d\n",getpid());
	printf("%d\n",getppid());
	
	pid = fork();
	if (pid > 0)
	{
		printf("process id:%d\n",getpid());
		printf("parent process id : %d\n",getppid());
		printf("I am in parent\n");
	}
	else if (pid == 0)
	{
		printf("process id:%d\n",getpid());
		printf("parent process id : %d\n",getppid());
		printf("I am in child\n");
	}
	else if (pid == -1)
	{
		perror("fork");
	}









	return 0;
}
