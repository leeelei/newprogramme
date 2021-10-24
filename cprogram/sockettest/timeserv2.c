#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<time.h>
#include<strings.h>
#include "socketlib.h"
#define PORTNUM 13000
#define HOSTLEN 256
#define oops(m) {perror(m);}
int main(int argc,char* argv[]){
	int sock_id,sock_fd;
	FILE* sock_fp;
	char* ctime();
	time_t thetime;
	sock_id=make_server_socket(PORTNUM);
	if(sock_id == -1)
		exit(1);
	printf("Server is ready!");
	while(1){
		sock_fd=accept(sock_id,NULL,NULL);
		printf("Wow! got a call! \n");
		if(sock_fd == -1)
			oops("accept");
		process_request(sock_fd);
		/*
		sock_fp=fdopen(sock_fd,"w");
		if(sock_fp ==NULL)
			oops("fdopen");
		thetime=time(NULL);
		fprintf(sock_fp,"The time here is ..");
		fprintf(sock_fp,"%s",ctime(&thetime));
		fclose(sock_fp);
		*/

	}
}
void process_request(int fd){
	time_t now;
	char* cp;
	time(&now);
	cp=ctime(&now);
	write(fd,cp,strlen(cp));
}
