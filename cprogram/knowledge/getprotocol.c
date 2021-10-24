#include<netdb.h>
#include<stdio.h>
void display_protocol(struct protoent* pt){
	int i=0;
	if(pt){
		printf("protocol name : %s,",pt->p_name);
		if(pt->p_aliases){
			printf("alias name: ");
			while(pt->p_aliases[i]){
				printf("%s ",pt->p_aliases[i]);
				++i;
			}
		}
		printf(",value:%d\n",pt->p_proto);
	}
}

int main(void){
	int i=0;
	const char* const protocol_name[]={
		"ip",
		"icmp",
		"igmp",
		"ggp",
		"ipencap",
		"st",
		"egp",
		"igp",
		"pup",
		"udp",
		"xns-idp",
		"rdp",
		NULL
	};
	setprotoent(1);
	while(protocol_name[i]!=NULL){
		//struct protoent* pt=getprotobyname((const char*)&protocol_name[i][0]);
		struct protoent* pt=getprotobyname(protocol_name[i]);
		if(pt){
			display_protocol(pt);
		}
		i++;
	}
	endprotoent();
	return 0;
}
