#include<stdio.h>
#include<stdlib.h>
int main(void){
	char c;
	while((c=getc(stdin)) !=EOF){
		printf("%c",c);
	}
	exit(0);
	return 0;
}
