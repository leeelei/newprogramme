#include<stdio.h>
int main(int argc,char* argv[]){
	printf("the account of argc is %d\n",argc);
	int i=1;
	while(i<argc){
		printf("the %dth is %s\n",i,argv[i]);
		i++;
	}
	return 0;
}
