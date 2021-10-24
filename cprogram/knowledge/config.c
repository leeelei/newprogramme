#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "config.h"

char* server_root;
char* db_addr;
char* db_user;
char* db_passwd;

struct conf_info clist[]={
	{"serverName",&server_root},
	{"dbAddr",&db_addr},
	{"dbUser",&db_user},
	{"dbPasswd",&db_passwd},
};

void trim(char* s){
	char* c=s+strlen(s)-1;
	while(isspace(*c) && c>s){
		*c='\0';
		--c;
	}
	if(c==s)
		*c='\0';
}
struct conf_info* lookup_keyword(char* c){
	struct conf_info *p;
	for(p=clist;p<clist+sizeof(clist);p++){
		if(strcasecmp(c,p->name) == 0)
			return p;
	}
	return NULL;
}

void apply_command(Cconf_info* p,char* args){
	if(p->object){
		if(*(char**)p->object !=NULL)
			free(*(char**) p->object);
		*(char**)p->object=strdup(args);
	}
}


void parse(FILE* fp){
	Cconf_info* p;
	char buf[1024],*c;
	int line=0;
	while(fgets(buf,2014,fp)!=NULL){
		++line;
		if(buf[0]=='\0' ||buf[0] == '#'|| buf[0] =='\n'){
			memset(buf,0,1024);
			continue;
		}
		trim(buf);
		if(buf[0]=='\0')
			continue;
		c=buf;
		while(!isspace(*c))
			++c;

		if(*c == '\0'){
			c=NULL;
		}else{
			*c='\0';
			++c;
		}
		p=lookup_keyword(buf);
		if(p!=NULL)
			apply_command(p,c);
		memset(buf,0,1024);
	printf("parse here !!!!\n");
				
	}
}
