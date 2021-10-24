#include<fcntl.h>
#include<stdio.h>
int main(int argc,char* argv[]){
	int val;
	FILE* fd=fopen("./passdemo","r");
	if((val=fcntl(atoi(fd),F_GETFL,0))<0){
		printf("it is here@@@@\n");
		printf("fcntl error for fd %d \n",fd);
	}
	//detective the attribute of file
	switch(val&O_ACCMODE){
		case O_RDONLY:
			printf("read only");
			break;
		case O_WRONLY:
			printf("write only");
			break;
		case O_RDWR:
			printf("read write");
			break;
		default:
			printf("unknow access mode");

	}
	if(val & O_APPEND)
		printf(", append");
	if(val & O_NONBLOCK)
		printf(", nonblocking");

#if defined(O_SYNC)
	if(val & O_SYNC)
		printf(", synchronous writes");
#endif
#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC)
	if(val & O_FSYNC)
		printf(", synchronous writes");
#endif
	putchar('\n');
	exit(0);
}
