#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<time.h>
#include<strings.h>

#define PORTNUM 15000
#define oops(msg) {perror(msg);exit(1);}

int main(int argc,char* argv[]){
	struct sockaddr_in saddr;

	int sock_id,sock_fd;
	FILE* sock_fpi,*sock_fpo;
	FILE* pipe_fp;
	char dirname[BUFSIZ];
	char command[BUFSIZ];
	char buf[100];
	int dirlen,c,i=0;
	int on=1;

	sock_id=socket(PF_INET,SOCK_STREAM,0);
	if(sock_id == -1){
		oops("socket");
	}
	if((setsockopt(sock_id,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on)))<0){
	        perror("setsockopt failed");
       		exit(1);
	}
	bzero((void*)&saddr,sizeof(saddr));
	saddr.sin_port=htons(PORTNUM);
	saddr.sin_family=AF_INET;
//	saddr.sin_addr.s_addr=inet_addr(argv
			//servadd.sin_addr.s_addr=inet_addr(argv[1]); //server ip
	if(bind(sock_id,(struct sockaddr*)&saddr,sizeof(saddr)) == -1)
		oops("bind");
	if(listen(sock_id,1) == -1)
		oops("listen");
	while(1){
		sock_fd=accept(sock_id,NULL,NULL);
		if(sock_fd == -1)
			oops("accept");
		if((sock_fpi=fdopen(sock_fd,"r")) == NULL)
			oops("fdopen reading");
		if(fgets(dirname,BUFSIZ-5,sock_fpi) ==NULL)
			oops("reading dirname");

		sanitize(dirname);

		if((sock_fpo=fdopen(sock_fd,"w")) == NULL)
			oops("fdopen wrting");
		sprintf(command,"ls %s",dirname);


		if((pipe_fp=popen(command,"r")) == NULL)
			oops("popen");


		while((c=getc(pipe_fp)) !=EOF){
			putc(c,sock_fpo);
		//	putc(c,stdout);
		}
		pclose(pipe_fp);
		fclose(sock_fpo);
		fclose(sock_fpi);

	}
	return 0;
}

sanitize(char* str){
	char* src,*dest;
	for(src=dest=str;*src;src++)
		if(*src =='/' || isalnum(*src))
			*dest++ =*src;
	*dest = '\0';
}



