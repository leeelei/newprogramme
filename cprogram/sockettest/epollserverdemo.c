#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<sys/epoll.h>

#define BUFFER_SIZE 40
#define MAX_EVENTS 10

int main(int argc,char* argv[]){
	int server_sockfd;
	int client_sockfd;
	int len;
	struct sockaddr_in my_addr;
	struct sockaddr_in remote_addr;

	int sin_size;

	char buf[BUFFER_SIZE];
	memset(&my_addr,0,sizeof(my_addr));

	my_addr.sin_family=AF_INET;
	my_addr.sin_addr.s_addr=INADDR_ANY;
	my_addr.sin_port=htons(8000);

	if(server_sockfd=socket(PF_INET,SOCK_STREAM,0)<0){
		perror("socket");
		return 1;
	}
	if(bind(server_sockfd,(struct sockaddr*)&my_addr,sizeof(struct sockaddr))<0){
		perror("bind");
		return 1;
	}

	listen(server_sockfd,5);
	sin_size=sizeof(struct sockaddr_in);

	int epoll
}
