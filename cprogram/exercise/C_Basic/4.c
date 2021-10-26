/*
 *  Write a C program to print the following characters in a reverse way
 * */
#include<stdio.h>
#include<string.h>
int main(){
	char* str="XML";
	int len=strlen(str);
	char* p=str+len-1;
	int i;
	printf("the reverse of XML is ");
	for(i=0;i<len;i++)
		printf("%c ",*p--);
	printf("\n");
	return 0;
}
