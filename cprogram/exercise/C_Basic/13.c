/*
 *Write a C program that accepts three integers and find the maximum of three
 */
#include<stdio.h>
int max(int* a,int *b){
	return *a>*b? *a:*b;	
}
int main(void){
	int a,b,c;
	int m;
	printf("Input the first integer: ");
	scanf("%d",&a);
	printf("Input the second integer: ");
	scanf("%d",&b);
	printf("Input the thrid integer: ");
	scanf("%d",&c);
	m=max(&a,&b);
	m=max(&m,&c);
	printf("Maximum value of three integers: %d\n",m);
	return 0;
}
