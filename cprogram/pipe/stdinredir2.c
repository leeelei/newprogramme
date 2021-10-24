#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
int main(void){
	int fd,newfd;
	char line[100];
	fgets(line,100,stdin);
	printf("%s",line);

	fgets(line,100,stdin);
	printf("%s",line);
	
	fgets(line,100,stdin);
	printf("%s",line);

	 fd=open("/etc/passwd",O_RDONLY);
	 if(fd == -1){
		 fprintf(stderr,"Could not open data as fd 0\n");
		 exit(1);
	 }
#ifdef CLOSE_DUP
	 close(0);
	 newfd=dup(fd);
#else
	 newfd=dup2(fd,0);
#endif
	 if(newfd !=0){
		 fprintf(stderr,"Could not duplicate fd to 0\n");
		 exit(1);
	 }
	 close(fd);

	fgets(line,100,stdin);
	printf("%s",line);

	fgets(line,100,stdin);
	printf("%s",line);
	
	fgets(line,100,stdin);
	printf("%s",line);

	return 0;
}

