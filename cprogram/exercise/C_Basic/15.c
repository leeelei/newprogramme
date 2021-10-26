/*
 *Write a C program that accepts three integers and find the maximum of three
 * */
#include<stdio.h>
#include<math.h>
int main(){
	float result;
	int x1,y1,x2,y2;
	printf("Input x1: ");
	scanf("%d",&x1);
	printf("Input y1: ");
	scanf("%d",&y1);
	printf("Input x2: ");
	scanf("%d",&x2);
	printf("Input y2: ");
	scanf("%d",&y2);
	result=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

	printf("Distance between the said points: %f\n",result);

	return 0;
}
