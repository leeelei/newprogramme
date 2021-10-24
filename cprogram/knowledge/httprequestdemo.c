#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<errno.h>


int main(int argc,char* argv[]){
	int socket_desc;
	struct sockaddr_in server;
	char* message;

	//create socket
	socket_desc=socket(AF_INET,SOCK_STREAM,0);
	if(socket_desc == -1){
		printf("could not create socket!\n");
	}

	char ip[20]={0};
//	char* hostname="www.cnblogs.com";
	char* hostname="www.baidu.com";
	struct hostent* hp;
	if((hp=gethostbyname(hostname))==NULL){
		return 1;
	}

	strcpy(ip,inet_ntoa(*(struct in_addr*)hp->h_addr_list[0]));
	printf("the ip is %s\n",hp->h_addr_list[0]);

	server.sin_addr.s_addr=inet_addr(ip);
	server.sin_family=AF_INET;
	server.sin_port=htons(80);


	//connect to remote server
	if(connect(socket_desc,(struct socketaddr*)&server,sizeof(server))<0){
		printf("connect error: %s\n",errno);
		return 1;
	}

	puts("Connected\n");

	//make some data
	//http protocol
	
	message="GET / HTTP/1.1\r\nHost: www.cnblogs.com\r\n\r\n";

	//send message to server
	if(send(socket_desc,message,strlen(message),0)<0){
		puts("send failed!");
		return 1;
	}


	puts("Data Send\n");

	//set timeout of socket
	struct timeval timeout={30,0};
	setsockopt(socket_desc,SOL_SOCKET,SO_RCVTIMEO,(char*)&timeout,sizeof(struct timeval));
	
	//Receive a reply from the server
	//loop
	int size_recv,total_size=0;
	char chunk[512];
	while(1){
		memset(chunk,0,512); //clear the variable
		//get the data
		if((size_recv=recv(socket_desc,chunk,512,0))==-1){
			if(errno==EWOULDBLOCK || errno==EAGAIN){
				printf("recv timeout ...\n");
				break;
			}else if(errno == EINTR){
				printf("interrupted by signal ...\n");
				continue;
			}else if(errno == ENOENT){
				printf("recv RST segement...\n");
				break;
			}else{
				printf("unkonwn error:%d\n",errno);
				exit(1);
			}
		}else if(size_recv ==0){
			printf("peer close ...\n");
			break;
		}else{
			total_size+=size_recv;
			printf("%s",chunk);
		}
	}
	printf("Reply recieved, total_size=%d bytes\n",total_size);
	return 0;
}
