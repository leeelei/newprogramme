#include<unistd.h>
#include<event.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.>
char* touppers(char* lpstr,int num){
	int i=0;
	char* p=lpstr;
	for(i=0;i<num;i++){
		p[i]=toupper(p[i]);
	}
	return lpstr;
}
void readcb(struct bufferevent* bev,void* ctx){
	struct evbuffer* input,*output;
	char* line;
	size_t nread,size,ret;
	char* buf=NULL;

	input=bufferevent_get_input(bev);
}
