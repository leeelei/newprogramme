#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<signal.h>
//extern void sig_process(int signo);
//extern void sig_pipe(int signo);

static int s;
void sig_process_client(int signo){
	printf("Catch a exit signal\n");
	close(s);
	exit(0);
}
void process_conn_client(int s){
	ssize_t size=0;
//	char buffer[1024]="*3\r\n$3\r\nSET\r\n$5\r\nmykey\r\n$5\r\nHello\r\n";
	char buffer[1024];
	for(;;){
		printf(">");
		fflush(stdout);
		size =read(0,buffer,1024);
		if(strcmp(temp,"quit") == 0){
			exit(0);
		}
		if(size>0){
			send(s,buffer,size,0);
			size=recv(s,buffer,1024,0);
			write(1,buffer,size);	
		}
	}
}
void sig_process(int signo){
	printf("Catch a exit signal\n");
	_exit(0);
}
void sig_pipe(int sign){
	printf("Catch a sigpipe signal\n");
}
#define PORT 6379
int main(int argc,char* argv[]){
	struct sockaddr_in server_addr;
	int err;
	if(argc==1){
		printf("please input server address\n");
		return 0;
	}	
	signal(SIGINT,sig_process_client);
	signal(SIGPIPE,sig_pipe);
	s=socket(AF_INET,SOCK_STREAM,0);
	if(s<0){
		printf("socket error\n");
		return -1;
	}

	//set server address
	bzero(&server_addr,sizeof(server_addr));
	server_addr.sin_family=AF_INET;
	server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	server_addr.sin_port=htons(PORT);

	inet_pton(AF_INET,argv[1],&server_addr.sin_addr);
	if(connect(s,(struct sockaddr*)&server_addr,sizeof(struct sockaddr))<0){
		perror("connect failure");
		return 1;
	}else
		printf("connect successfully!\n");
	process_conn_client(s);
	close(s);
}
