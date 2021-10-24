#include<stdio.h>
int main(int argc,char *argv[]){
	int x=1,y=2,z[10],t=25,s=0;
	int *ip;
	ip=&x;
	y=*ip;
	s=*&t;
	printf("y is %d\n",y);
	printf("s is %d\n",s);
	return 0;
}

