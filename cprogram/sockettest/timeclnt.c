#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#define oops(msg) {perror(msg);}
int main(int argc,char* argv[]){
	struct sockaddr_in servadd;
	int sock_id,sock_fd;
	char message[BUFSIZ];
	int messlen;

	sock_id=socket(AF_INET,SOCK_STREAM,0);
	if(sock_id == -1)
		oops("socket");
	bzero(&servadd,sizeof(servadd));

	servadd.sin_port=htons(atoi(argv[2])); //server port
	servadd.sin_family=AF_INET;
	servadd.sin_addr.s_addr=inet_addr(argv[1]); //server ip
	if(connect(sock_id,(struct sockaddr*)&servadd,sizeof(servadd))!=0)
		oops("connect");
	messlen=read(sock_id,message,BUFSIZ);
	if(messlen == -1)
		oops("read");
	if(write(1,message,messlen) != messlen)
		oops("write");
	close(sock_id);
}
