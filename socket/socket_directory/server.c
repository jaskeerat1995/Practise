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
	
void bind_socket(int sockfd)
{	
	
	struct sockaddr_in my_addr;
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(5000);
//	my_addr.sin_addr.s_addr = INADDR_LOOPBACK;
	my_addr.sin_addr.s_addr = INADDR_ANY;
	if (bind(sockfd,(struct sockaddr *) &my_addr, sizeof(struct sockaddr_in)) < 0)
	{
		perror("bind");
		exit(EXIT_FAILURE);
	}		
}

void listen_socket(int sockfd)
{
	if (listen(sockfd,LISTEN_BACKLOG) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
}

int accept_socket(int sockfd)
{
	struct sockaddr_in peer_addr;
	int peer_addr_len, new_fd;
	peer_addr_len = sizeof(struct sockaddr_in);
	new_fd = accept(sockfd, (struct sockaddr *)&peer_addr, &peer_addr_len);
	if (new_fd < 0)
	{
		perror("accept");
		exit(EXIT_FAILURE);	
	}
	printf("%s : new_fd = %d\n",__FILE__,new_fd);

	return new_fd;
}	
	
int main()
{	
	int ret, sfd, bytes, fd, num;
	char buff[50];
	DIR *dirp = NULL;
	struct dirent *dp = NULL;
	
	//fd = open("/root/socket/FILE",O_RDWR);
	ret = create_socket();
	bind_socket(ret);
	listen_socket(ret);
	sfd = accept_socket(ret);
//	while(1)
//	{
/*		printf("Check directory or not       :   press 1\n");
		printf("Check files inside directory :   press 2\n");
		printf("Change permissions of directory or files  : press 3\n");
		printf("Download file if file exit   :    press 4\n");
*/		//scanf("%d",&num);
	//	switch(num)
	//	{
			
	//	}
		bytes = read(sfd,buff,sizeof(buff));	
		printf("bytes read: %d\n",bytes);
		printf("%s\n",buff);
		dirp = opendir(buff);
		if (dirp == NULL)
		{
			perror("opendir");
			exit(EXIT_FAILURE);
		}
		else
		{
			printf("Exist\n");
		}
	
		while((dp = readdir(dirp)) != NULL)
		{
		if (dp == NULL)
		{
			perror("readdir:");
			exit(EXIT_FAILURE);
		}
		else
		{
			printf("%s\t\t",dp->d_name);	
			printf("%ld\n",(ino_t)dp->d_ino);	
		}
		}
		
		memset(buff,'\0',sizeof(buff));
		bytes = read(sfd,buff,sizeof(buff));	
		printf("%s\n",buff);
		printf("bytes read: %d\n",bytes);
		fd = open(buff,O_RDONLY);			
		if (fd < 0)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
		printf("%s : fd = %d\n",__FILE__,fd);
		write(fd,);		

//	}
	close(dirp);
	close(sfd);
	return 0;
}	
