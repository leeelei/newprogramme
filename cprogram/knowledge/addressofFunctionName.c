#include<stdio.h>
void MyFun(int x);
int main(int argc,char* argv[]){
	printf("The address of Function MyFun is 0x%x\n",MyFun);
	MyFun(10);
	return 0;
}

void MyFun(int x){
	printf("%d\n",x);
}
