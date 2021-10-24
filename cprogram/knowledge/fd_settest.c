#include<sys/select.h>
#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
int main(void){
	fd_set set;
	FD_ZERO(&set);

	int i;
	for(i=0;i<32;i++)
		printf("set.__fds_bits[%d]:%ld\t",i,set.__fds_bits[i]);
	printf("\n///////////////////////////////////////\n");


	FD_SET(10,&set);

	for(i=0;i<32;i++)
		printf("set.__fds_bits[%d]:%ld\t",i,set.__fds_bits[i]);

	return 0;
}
