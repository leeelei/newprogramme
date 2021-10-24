#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_LINE (1024)
#define SERVER_PORT (7778)
void setnoblocking(int fd){
	int opts=0;
	opts=fcntl(fd,F_GETFL);
	opts=opts|O_NONBLOCK;
	fcntl(fd,F_SETFL);
}

int main(int argc,char* argv[]){
	int sockfd;
	char recvline[MAX_LINE+1]={0};
	struct sockaddr_in server_addr;
	if(argc!=2){
		fprintf(stderr,"Usage ./client <SERVER)IP>\n");
		exit(0);
	}

	//create client socket
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0){
		fprintf(stderr,"socket error\n");
		exit(0);
	}

	//server addr assignment
	bzero(&server_addr,sizeof(server_addr));
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(SERVER_PORT);

	if(inet_pton(AF_INET,argv[1],&server_addr.sin_addr)<0){
		fprintf(stderr,"inet_pton error for %s\n",argv[1]);
		exit(0);
	}

	//connect the server
	if(connect(sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr))<0){
		perror("connect!");
		fprintf(stderr,"connect error\n");
		exit(0);
	}
	

	setnoblocking(socket);
	char input[100];
	int n=0;
	int count=0;

	//read the char from stdin continuously
	while(fgets(input,100,stdin) !=NULL){
		printf("[send]qiguai %s\n",input);
		n=0;
		n=send(sockfd,input,strlen(input),0);
		if(n<0)
			perror("send error");
		n=0;
		count=0;
		while(1){
			n=read(sockfd,recvline+count,MAX_LINE);
			if(n==MAX_LINE){
				count+=n;
				continue;
			}else if(n<0){
				perror("recv");
				break;
			}else{
				count+=n;
				recvline[count]='\0';
				printf("[recv]: %s\n",recvline);
				break;
			}
		}
	}
	return 0;
	
}
