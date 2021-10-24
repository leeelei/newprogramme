#include<ctype.h>
#include<stdio.h>
int main(){
	char ch;
	printf("input a character: ");
	scanf("%c",&ch);
	if(isspace(ch)){
		printf("%c is space.",ch);
	}else
		printf("%c is not space.",ch);
	putchar('\n');
	return 0;
}
