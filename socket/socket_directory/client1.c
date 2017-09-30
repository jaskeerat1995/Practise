#include"header.h"


int create_socket()
{
        int sockfd;

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0)
        {
                perror("socket");
                exit(EXIT_FAILURE);
        }
        printf("%s : sockfd = %d\n",__FILE__,sockfd);
        return sockfd;
}

void connect_socket(int sockfd)
{
	struct sockaddr_in my_addr;
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(5000);
	my_addr.sin_addr.s_addr = inet_addr("192.168.1.111"); 
	if (connect(sockfd,(struct sockaddr *)&my_addr, sizeof(struct sockaddr_in)) < 0)
	{
		perror("connect");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("socket connected\n");
	}

}
int main(int argc, char *argv[])
{
	int fd, bytes;
	char buff[100];
	if(argc != 1)
	{
		printf("insufficent argument\n");
		return 0;
	}
	//	scanf("%s",argv[1]);
//	strcpy(buff,argv[1]);
	fd = create_socket();
	connect_socket(fd);
//	fgets(buff,sizeof(buff),fd);
	scanf("%s",buff);
//	printf("%s\n",argv[1]);
	bytes = send(fd,buff,strlen(buff),0);
	printf("bytes send: %d\n",bytes);
	
//	chmod("/root/socket/socket_directory/file",S_IRUSR|S_IWUSR|S_IWGRP|S_IRGRP);
	
	
	if (fchmodat(fd,"/root/practise/socket/FUCKYOU",0666,0) < 0)
	{
		perror("fchmodat");
		exit(EXIT_FAILURE);
	}
	
/*	if (fchmodat(fd,argv[1],0666,0) < 0)
	{
		perror("fchmodat");
		exit(EXIT_FAILURE);
	}
*/	
	memset(buff,'\0',sizeof(buff));
	scanf("%s",buff);
	bytes = send(fd,buff,strlen(buff),0);
        printf("bytes send: %d\n",bytes);
	//bytes = read(fd,)	
	//printf("bytes send: %d\n",bytes);
			
	
	close(fd);
	
	return 0;

}
