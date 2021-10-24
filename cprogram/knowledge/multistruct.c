#include<stdio.h>
#include<stdbool.h>

struct sub{
	int i;
	char* a;
};
struct test{
	struct {
		int i;
		char* a;
	};
	bool sex;
	short b;
};
int main(){
	printf("the isze of int is %ld\n",sizeof(int));
	printf("the isze of char* is %ld\n",sizeof(char*));
	printf("the isze of bool is %ld\n",sizeof(bool));
	printf("the isze of short is %ld\n",sizeof(short));
	printf("the isze of sub is %ld\n",sizeof(struct sub));
	printf("the isze of test is %ld\n",sizeof(struct test));
	return 0;
		
}       		
        		
        		
