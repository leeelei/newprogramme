#include<stdio.h>
#include<string.h>
int main(){
	char str[]="mv a.c b.c";
	char *p;
	p =strtok(str," ");
	while(p){
		printf("%s\n",p);
		p=strtok(NULL," ");
	}
	return 0;
}
