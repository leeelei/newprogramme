#include<stdio.h>
#include<stdlib.h>
#include "socketlib.h"
/*
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<errno.h>
*/
#define oops(msg) {perror(msg);}
void talk_with_server(int fd){
	char buf[BUFSIZ];
	int n;
	n=read(fd,buf,BUFSIZ);
	write(1,buf,n);
}

int main(int argc,char* argv[]){
	int sock_id;
	char message[BUFSIZ];
	int messlen;
	sock_id=connect_to_server(argv[1],atoi(argv[2]));
	if(sock_id==-1){
		printf("sock_id return wrong!!\n");
		exit(1);
	}
	talk_with_server(sock_id);
	messlen=read(sock_id,message,BUFSIZ);
	if(messlen == -1)
		oops("read");
	if(write(1,message,messlen) != messlen)
		oops("write");
	close(sock_id);
	return 0;
}
/*
int connect_to_server(const char* host,int portnum){
       struct sockaddr_in servadd;
       int sock;
       sock=socket(AF_INET,SOCK_STREAM,0);
       if(sock== -1)
               return -1;
       bzero(&servadd,sizeof(servadd));
       printf("The portnum is %d\n",portnum);

       //servadd.sin_port=htons(portnum);
       servadd.sin_port=htons(portnum);
       servadd.sin_family=AF_INET;
       servadd.sin_addr.s_addr=inet_addr(host); //server ip
//       servadd.sin_addr.s_addr=inet_addr("127.0.0.1"); //server ip
        printf("connect the host is %s\n",host);
        if(connect(sock,(struct sockaddr*)&servadd,sizeof(servadd))!=0){
                printf("%d\n",errno);
                printf("socketlib call@@@\n");
                return -1;
        }
        return sock;
}

*/
