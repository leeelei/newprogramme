#include<stdio.h>
int max(int a,int b){
	return a>b ? a :b ;
}
int min(int a,int b){
	return a<b ? a :b ;
}
int (*f)(int,int);
int main(void){
	printf("---------------------Start\n");
	f=max;
	int c=(*f)(1,2);
	printf("The max value is %d\n",c);

	f=min;
	c=(*f)(1,2);
	printf("The min value is %d\n",c);
	printf("---------------------End\n");
	getchar();
	return 0;
}
