

#include<sys/types.h>
#include<sys/socket.h>
#include <sys/socket.h>

int main(int argc,char** argv){
	int fd,val;
	socklen_t len;
	char strres[128];
	len=sizeof(val);
	fd=socket(AF_INET,SOCK_STREAM,0);
	if(getsockopt(fd,SOL_SOCKET,SO_RCVBUF,&val,&len)==-1)
		printf("getsockopt error");
	else{
		if(len != sizeof(int)){
			printf("len is %d\n",len);
		}else
			printf("val is %d\n",val);
	}
	close(fd);
	return 0;
}
