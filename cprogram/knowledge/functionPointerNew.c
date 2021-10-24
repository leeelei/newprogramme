#include<stdio.h>
char (*pFun)(int);
char glFun(int a){
	return a;
}
void main(void){
	pFun = glFun;
	printf("pFun is %d\n",(*pFun)(2));

}
