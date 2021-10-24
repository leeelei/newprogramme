#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>


int main(int argc,char* argv[]){
	struct in_addr ip,local,network;
	char addr1[]="192.168.1.1";
	char addr2[]="255.255.255.255";
	char addr3[]="192.168.1";
	char* str=NULL,*str2=NULL;
	int err=0;

	err=inet_aton(addr1,&ip);
	if(err){
		printf("inet_aton:string %s  value is:0x%x\n",addr1,ip.s_addr);
	}else{
		printf("ient_aton:string %s error \n",addr1);	
	}


	ip.s_addr=inet_addr(addr1);
	if(ip.s_addr != -1)
		printf("inet_addr:string %s  value is:0x%x\n",addr1,ip.s_addr);
	else
		printf("ient_aton:string %s error \n",addr1);	

	ip.s_addr=inet_addr(addr2);
	if(ip.s_addr != -1)
		printf("inet_addr:string %s  value is:0x%x\n",addr2,ip.s_addr);
	else
		printf("ient_aton:string %s error \n",addr2);	
		
	return 0;
}
