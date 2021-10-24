#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include "socketlib.h"

void main(int argc,char* argv[]){
	int sock,fd;
	FILE* fpin;
	char request[BUFSIZ];
	if(argc == 1){
		fprintf(stderr,"Usage: ws portnum\n");
		exit(1);
	}
	sock=make_server_socket(atoi(argv[1]));
	if(sock==-1)
		exit(2);

	while(1){
		fd=accept(sock,NULL,NULL);
		fpin=fdopen(fd,"r");

		fgets(request,BUFSIZ,fpin);
		printf("got a call: request = %s",request);
//		read_til_crnl(fpin);
		process_rq(request,fd);
		fclose(fpin);
	}
}
read_til_crnl(FILE* fp){
	char buf[BUFSIZ];
	while(fgets(buf,BUFSIZ,fp) !=NULL && strcmp(buf,"\r\n") !=0);
}
process_rq(char* rq,int fd){
	char cmd[BUFSIZ],arg[BUFSIZ];
	if(fork() !=0)
		return;
	strcpy(arg,"./");
	if(sscanf(rq,"%s%s",cmd,arg+2)!=2){
		printf("it is here@@ %s\n",rq);
		return;
	
	}

	if(strcmp(cmd,"GET") !=0){
		printf("it is here@@ %d %s\n",__LINE__,cmd);
		cannot_do(fd);
	}
	/*
	else if(not_exist(arg))
		do_404(arg,fd);
	else if(isadir(arg))
		do_ls(arg,fd);
	else if(ends_in_cig(arg))
		do_exec(arg,fd);
	else
		do_cat(arg,cfd);
		*/
}


header(FILE* fp,char* content_type){
	fprintf(fp,"HTTP/1.0 200OK\r\n");
	if(content_type)
		fprintf(fp,"Content-type: %s\r\n",content_type);
}

cannot_do(int fd){
	printf("it is here@@cant not do  %d \n",__LINE__);
	FILE* fp=fdopen(fd,'w');
	fprintf(fp,"HTTP/1.0 501 Not Implemented\r\n");
	fprintf(fp,"Content-type: text/plain\r\n");
	fprintf(fp,"\r\n");
	fprintf(fp,"That command is not yet implemented\r\n");
	fclose(fp);

}
