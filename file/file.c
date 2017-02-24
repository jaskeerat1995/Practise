#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
	int fd;
	char arr[] = "Writing some content......\n\n";
	fd = open("ffff", O_RDWR | O_CREAT);
	if (fd < 0)
	{
		perror("open");
		exit(EXIT_SUCCESS);
	}
	write(fd,arr,sizeof(arr));
	
	return 0;
}
