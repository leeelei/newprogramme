/*
 *Write a C program to compute the perimeter and area of a rectangle with a height of 7 inches. and width of 5 inches.
 */
#include<stdio.h>
int main(void){
	int height=7;
	int width=5;
	printf("Perimeter of the rectangle = %d inches\n",2*(height+width));
	printf("Area of the rectangle = %d square inches\n",height*width);
	return 0;
}
