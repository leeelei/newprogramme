#include<stdio.h>
int main(void){
	char* str="hello world!";
	char* p;
	int account=0;
	for(p=str;*p;p++)
		if(*p == 'l')
			account+=1;
	printf("the num is %d\n",account);
	return 0;
}

