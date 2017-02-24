#include<stdio.h>
//#include<sys/wait.h>
#include<signal.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int flag = 0;	

void mysignal(int sig)
{
	flag = 1;
	printf("got signal\n");
}
	
/*int raise(int sig)
{
	printf("sig no. %d\n",sig);
	return 0;
}
*/
	
int main()
{	
	int arr[2], i, ret;
	char rfd[4],wfd[4];
	char *p = "This is Shashank Arora";
	//char *a = (char *)malloc(sizeof(char) * strlen(p));
	char a[50];
	int bytes;
	(void) signal(SIGTSTP,mysignal);
	
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
while(1){
	switch(pid)
	{
	case -1:	printf("error in fork\n");
			break;
			
	case 0: 	if (flag == 1){
			
			printf("This is child process\n");
			printf("pid = %d\n",getpid());
			printf("ppid in child= %d\n",getppid());
			bytes = read(*(arr+i),&a,sizeof(a));	
			printf("Bytes read: %d\n",bytes);
			flag = 0;
			}
			break;
	default:	printf("This is parent\n");
			bytes = write(*(arr + i + 1), p, strlen(p));
			//wait();
			printf("Bytes written: %d\n",bytes);
//			ret = kill(getppid(),10);
			flag = 1;
			if (ret < 0){
				perror("kill");
				goto OUT;
			}
		
	}
}	
	return 0;
OUT:	return -1;
}	
	
