#include<stdio.h>
int main(void){
	char buf[]="hellow world!";
	char c;
	while((c=getc(stdin)) != EOF)
		printf("%c",c);
//		putc(c,stdout);
	return 0;
}
