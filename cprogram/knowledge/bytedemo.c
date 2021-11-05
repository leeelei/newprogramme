#include<stdio.h>
#include<stdlib.h>
int main(){
	char arr[1024*1024];
	FILE* fp;
	int i;
	for(i=0;i<sizeof(arr);i++){
		arr[i]='a';
	}
	fp=fopen("./byte.txt","w");
	for(i=0;i<sizeof(arr);i++){
		fputc(arr[i],fp);
	}
	fclose(fp);
	return 0;
}
