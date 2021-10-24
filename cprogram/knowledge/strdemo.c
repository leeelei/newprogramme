#include<stdio.h>
#include<string.h>
int main(void){
	char* str="hello";
	char* p=str;
	for(;*p != NULL;p++)
		printf("%c\n",*p);
	printf("the first char is %c\n",*str);

	return 0;
}
