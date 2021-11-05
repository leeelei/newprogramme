#include<stdio.h>
#include<stdlib.h>
int main(){
	int i=1;
	while(1){
		printf("inside while(1) \n");
		while(i++){
			printf("i=%d\n",i);
			if(i>3)
				goto jumpout;
		}
		printf("continue?\n");
	}
jumpout:
	printf("finished!\n");
	return 0;
}
