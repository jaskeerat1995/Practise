#include<stdio.h>
//#include<sys/wait.h>
#include<signal.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include"header.h"

int flag = 0;

void sig(int s)
{
	printf("got signal no. %d\n",s);
	flag = 1;
}	

int main()
{	
	int arr[2], i, ret;
	char rfd[4],wfd[4], PID[10];
	struct data str;
//	printf("%s\n",str.c);
	//char *a = (char *)malloc(sizeof(char) * strlen(p));
	char a[50];
	int bytes;
	
//	(void)signal(2,sig);
	
	i = 0;
	{
		if(pipe(arr+i) < 0)
		{
			perror("pipe");
			goto OUT;
		}
		printf("%d\n",*(arr + i));
		printf("%d\n",*(arr + i + 1));
	i += 2;
	}
	pid_t pid;
	printf("pid in parent= %d\n",getpid());
	printf("ppid in parent= %d\n",getppid());
	i = 0;
	pid = fork();
//while(1){
	switch(pid)
	{
	case -1:	printf("error in fork\n");
			break;
				
	case 0: //	if (flag == 1){
			sleep(1);
			printf("This is child process\n");
			printf("pid of child= %d\n",getpid());
			printf("ppid in child= %d\n",getppid());
			sprintf(rfd,"%d",*(arr+0));
			sprintf(wfd,"%d",*(arr+1));
			sprintf(PID, "%d", getpid());
			execl("./client_pipe","./client_pipe",rfd,wfd,PID,NULL);
			//bytes = read(*(arr+i),&a,sizeof(a));	
			printf("Bytes read: %d\n",bytes);
		//	flag = 0;
		//	}
			break;
	default:	printf("This is parent\n");
		//	str.c = "This is Shashank Arora";
		//	printf("%d\n",*(arr + i));
		//	printf("%d\n",*(arr + i + 1));
			str.d = 54;
			bytes = write(*(arr + i + 1), &str, sizeof(struct data));
			printf("%s\n",str.c);
			printf("Bytes written: %d\n",bytes);
		//	kill(getppid(),sig);
	}
//}	
/*	pause();
	if (flag == 1)
	{
		printf("read!!");
	}

*/
	return 0;
OUT:	return -1;
}	
	
