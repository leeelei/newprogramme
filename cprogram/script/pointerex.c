#include<stdio.h>
#include<unistd.h>
int main(int argc,char* argv[]){
	char *p="hello";
	printf("%s\n",p);
	puts(p);
	printf("%c\n",*p);
	printf("%x\n",p);
	printf("%p\n",p);
	return 0;
}

	
