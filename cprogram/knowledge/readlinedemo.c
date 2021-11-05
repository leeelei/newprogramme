#include<stdio.h>
#include<readline/readline.h>
int main(){
	char a[]="please input a string\n";
	char* input=readline(a);
	printf("%s\n",input);
	return 0;
}
