#include<stdio.h>
#include "config.h"
#include<stdlib.h>

extern char* server_root;
extern char* db_addr;
extern char* db_user;
extern char* db_passwd;

int main(void){
	FILE* fp;
	if((fp=fopen("test.conf","r")) ==NULL){
		fprintf(stderr,"Cann't open config file %s.\n","test.conf");
		exit(1);
	}
	parse(fp);
	printf("it is here main!!@@@\n");
	printf("ServerRoot is : %s \n",server_root);
	printf("Database address is : %s \n",db_addr);
	printf("Database user is : %s \n",db_user);
	printf("Database passwd is : %s \n",db_passwd);
	return 0;
}

