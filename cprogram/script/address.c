#include<stdio.h>
#include<stdlib.h>
int main(void){
	int arr[10]={0};
	int* p=arr;
	/*
	for(int i =0;i<sizeof(arr)/sizeof(arr[0]);i++){
		printf("%d\n",arr[i]);
		}
		*/
	printf("The address is %p \n",arr);
	printf("The address is %p \n",&arr[0]);
	printf("The address is %p \n",p);
	return 0;

}
