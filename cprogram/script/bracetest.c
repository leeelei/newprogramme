#include<stdio.h>
//the brace means a domain of statement;
int main(void){
	int a=1;
	{
		//a is a local variable
		int a=2;
		printf("a is %d\n",a);
	}
		printf("a is %d\n",a);
		return 0;
}
