#include<stdio.h>
#define NGX_MODULE_V1_PADDING  0, 0, 0, 0, 0, 0, 0, 0

struct test{
	int a1;
	int a2;
	int a3;
	int a4;
	int a5;
	int a6;
	int a7;
	int a8;
};
int main(void){
//	struct test demo = {0,0,0,0,0,0,0,0};
	struct test demo={NGX_MODULE_V1_PADDING};
//	demo = {0,0,0,0,0,0,0,0};
	printf("a1 is %d\n",demo.a1);
	return 0;
}
