/*
 * Write a C program to compute the perimeter and area of a circle with a given radius
 */
#define PI 3.14
#include<stdio.h>
int main(void){
	int radius=6;
	printf("Perimeter of the circle = %lf inches\n",2*PI*radius);
	printf("Area of the circle = %lf square inches\n",PI*radius*radius);
	return 0;
}
