#include<stdio.h>
int main(void){
	int a=3;
	int b=4;
	int c=5;
	const int* p1;
	int* const p2=&b;
	p1=&a;
//	p2=&b;
	printf("the value of a is %d\n",*p1);
	printf("the value of b is %d\n",*p2);

	//*p1=1;
//	printf("the value of a is %d\n",*p1);
	*p2=100;
	printf("the value of b is %d\n",*p2);
	p2=&c;
	return 0;
}
