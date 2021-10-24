#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
 struct hostent *h;
 char hostname[40];
 int i=0;
 char ip[20]={0};
 printf("请输入域名\n");
 scanf("%s",hostname);
 getchar();
 if((h=gethostbyname(hostname))==NULL)
 {
     fprintf(stderr,"不能得到IP\n");
     exit(1);
 }
 printf("HostName :%s\n",h->h_name);
 printf("IpType :%d\n",h->h_addrtype);
 printf("h_length :%d\n",h->h_length);
// printf("Ip address: %s\n",inet_ntoa(*((struct in_addr*)h->h_addr_list[0])));
strcpy(ip, inet_ntoa(*(struct in_addr *)h->h_addr_list[0]));
// printf("Ip address: %s\n", ip);
 /*
 while(h->h_addr_list[i]){
 	char ip[20];
	memcpy(&ip,inet_ntoa(*((struct in_addr*)h->h_addr_list[i])),20);
	printf("%s\n",ip);
	memset(ip,'\0',20);
	i++;
 }
 */
// printf("IP Address :%s/n",inet_ntoa(*((struct in_addr *)h->h_addr)));
  return EXIT_SUCCESS;
}
