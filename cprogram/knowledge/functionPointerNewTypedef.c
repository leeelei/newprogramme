#include<stdio.h>
typedef char (*PTRFUN)(int);

PTRFUN pFun;
char glFun(int a){
	return a;
}
void main(void){
	pFun = glFun;
	printf("pFun is %d\n",(*pFun)(2));

}
