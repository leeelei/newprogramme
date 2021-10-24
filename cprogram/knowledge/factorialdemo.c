#include<stdio.h>
int factorial(int f){
	if(f==0){
		return 1;
	}else{
		return f*factorial(f-1);
	}
}
int main(){
	int fac=0;
	printf("input a number: ");
	scanf("%d",&fac);

	printf("the result is %d\n",factorial(fac));
	return 0;
}
