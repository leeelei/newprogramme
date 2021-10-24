//about buffer test
#include<stdio.h>
#include<unistd.h>
int main(){
	printf("the first Hello world!\n");
	printf("the second Hello world!");
	while(1){
		sleep(1);
	}
	return 0;
}
//the program above has called the funciton printf,but it does not print anything
//because the program is always in the while circle,only when there is a '\n',the function printf can print something
//there is a buffer where the string is inside ,where finish run ,the string can be printed.

