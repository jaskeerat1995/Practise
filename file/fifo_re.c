#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	int fd, bytes;
	char arr[100];
	fd = open("FIFO_STREAM", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		exit(EXIT_SUCCESS);
	}
	printf("process ID %d\n",getpid());
	bytes = read(fd,arr,sizeof(arr));
	printf("%d\n",bytes);
	
	return 0;
}
