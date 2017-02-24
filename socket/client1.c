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
	my_addr.sin_addr.s_addr = inet_addr("192.168.28.128"); 
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

int main()
{
	int fd, bytes;
	char buff[50];
	fd = create_socket();
	connect_socket(fd);
	while(1)
	{
		
	}


	close(fd);
}
