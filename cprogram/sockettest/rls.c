#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#define oops(msg) {perror(msg);exit(1);}
#define PORTNUM 15000
int main(int argc,char* argv[]){
	struct sockaddr_in servadd;
	int sock_id;
	char buffer[BUFSIZ];
	int n_read;

	if(argc!=3){
		printf("Usage: command arg1,arg2\n");	
		exit(1);
	}
	sock_id=socket(AF_INET,SOCK_STREAM,0);
	if(sock_id == -1)
		oops("socket");
	bzero(&servadd,sizeof(servadd));

	servadd.sin_port=htons(PORTNUM);
	servadd.sin_family=AF_INET;
	servadd.sin_addr.s_addr=inet_addr(argv[1]); //server ip

	if(connect(sock_id,(struct sockaddr*)&servadd,sizeof(servadd)) != 0)
		oops("connect");
	if(write(sock_id,argv[2],strlen(argv[2])) == -1)
		oops("write");
	if(write(sock_id,"\n",1) == -1)
		oops("write");
	while((n_read=read(sock_id,buffer,BUFSIZ)) >0)
		//printf("%s\n",buffer);
		if(write(1,buffer,n_read) == -1)
			oops("write");
	close(sock_id);
}

