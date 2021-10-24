#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>

int main(int argc,char* argv[]){
	char* ptr,**pptr;
	struct hostent* hptr;
	char str[32]={0};

	ptr=argv[1];
	if((hptr=gethostbyname(ptr))==NULL){
		printf("gethostbyname error: %s\n",ptr);
		return 0;
	}

	printf("official hostname: %s \n",hptr->h_name);
	for(pptr=hptr->h_aliases;*pptr !=NULL;pptr++){
		printf("alias: %s \n",*pptr);	
	}

	switch(hptr->h_addrtype){
		case AF_INET:
		case AF_INET6:
			pptr=hptr->h_addr_list;
			for(;*pptr!=NULL;pptr++){
//				printf("Address: %s\n",inet_ntop(hptr->h_addrtype,*pptr,str,sizeof(str)));
				printf("address: %s\n", inet_ntop(hptr->h_addrtype, *pptr, str, sizeof(str)));   //inet_ntop: 将网络字节序的二进制转换为文本字符串的格式

//				printf("first address: %s\n",inet_ntop(hptr->h_addrtype,hptr->h_addr_list[0],str,sizeof(str)));
			}
			break;
		default:
			printf("unknown address type\n");
			break;

	}
	return 0;
}
