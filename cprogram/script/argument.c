#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "smsh.h"
char* next_cmd(char* prompt,FILE* fp){
	char* buf;
	int bufspace=0;
	int pos=0;
	int c;
	printf("%s",prompt);
	while((c=getc(fp))!=EOF){
		if(pos+1 >=bufspace){
			if(bufspace ==0){
				buf=malloc(BUFSIZ);
			}else{
				buf=realloc(buf,bufspace+BUFSIZ);
			}
			bufspace+=BUFSIZ;
		}
			if(c=='\n')
				break;
			buf[pos++]=c;
		}
	if(c==EOF&&pos==0)
		return NULL;
	buf[pos]='\0';
	return buf;
}
int main(void){
	char* str;
	str=next_cmd("test>",stdin);
	printf("the argument is\" %s\"\n",str);
	return 0;
}
