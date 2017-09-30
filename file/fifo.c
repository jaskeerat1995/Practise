#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int fd, bytes;
	char arr[] = "Writing some content......\n\n";
	mkfifo("FIFO_STREAM",0777);
	fd = open("FIFO_STREAM", O_WRONLY);
	if (fd < 0)
	{
		perror("open");
		exit(EXIT_SUCCESS);
	}
	printf("process ID: %d\n",getpid());
	bytes = write(fd,arr,sizeof(arr));
	
	printf("bytes = %d\n",bytes);
	
	return 0;
}


