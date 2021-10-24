#include<stdio.h>
#include<stdlib.h>
int main(void){
	void* p;
	p=malloc(1024);
	printf("The length mem is %d\n",sizeof(p));
//	int a[10]={0};
//	printf("The length is %d\n",sizeof(a));
	return 0;
}
