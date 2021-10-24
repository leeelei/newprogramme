#include<stdio.h>
int *f(int a, int b);
int *f1(int a, int b);
int main(void){
	printf("------------------------------Start\n");
	int *p1 =NULL;
	int *p2 =NULL;
	printf("The memory address of p1= 0x%x\n",p1);
	printf("The memory address of p2= 0x%x\n",p2);
	printf("------------------------------\n");

	p1=f(1,2);
	p2=f1(3,4);
	printf("------------------------------\n");
	printf("The memory address of p1= 0x%x\n",p1);
	printf("The memory address of p2= 0x%x\n",p2);
	printf("*p1 =%d\n",*p1);
	printf("*p2 =%d\n",*p2);

	printf("------------------------------End\n");
	getchar();
	return 0;
}
int *f(int a,int b){
	int *p =(int*)malloc(sizeof(int));
	printf("The memory address of p = 0x%x\n",p);
	memset(p,0,sizeof(int));
	*p=a+b;
	printf("*p = %d \n",*p);
	return p;
	}
//after funcion is called,local variable will be vanished.
int *f1(int a, int b){
	int sum=0;
	sum=a+b;
	printf("The memory address of p21111111111111 = 0x%x\n",&sum);
	return &sum;
}
