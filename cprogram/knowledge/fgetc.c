#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[]){
	char b[50]={0};
	char a[100];
	int i;
	FILE* fp=fopen("chartext","r");
	if(NULL == fp){
		printf("fopen\n");
		return -1;
	}

/*	
	if(fgets(a,2,fp) != NULL){
		printf("the char is %d\n",*a);
		printf("the char is %d\n",*(a+1));
		printf("the size is %d\n",sizeof(a));
	}
	*/


	while(fgets(b,50,fp) !=NULL){
		int count=0;
		for(i=0;b[i] != 0;i++){
			if(!isspace(b[i])&&isalpha(b[i]))
				printf("%c",b[i]);
			if(b[i] == ' ')
				count+=1;

		}
		printf("              the number of space is %d\n",count);
		printf("\n");
		//	putchar(b[i]);
		//	printf("%s",b);
	}
		
	return 0;

}
