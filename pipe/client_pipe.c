#include<stdio.h>
//#include<sys/wait.h>
#include<signal.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include"header.h"


int main(int argc, char *argv[])
{
	int rfd, bytes, ppid;
//	char *buff = (char *)malloc(sizeof(char) * 40);
	struct data str;
	rfd = atoi(argv[1]);
	ppid = atoi(argv[3]);
//	printf("rfd in execl = %d\n",rfd);
//	printf("ppid in execl = %d\n",ppid);
	bytes = read(rfd,&str,sizeof(struct data));
	printf("no of bytes read: %d\n",bytes);
	printf("d = %d\n",str.d);
	printf("read = %s\n",str.c);			
//	kill(ppid,2);	
}
