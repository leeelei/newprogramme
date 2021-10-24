#include<stdio.h>
struct {
	unsigned int widthValidated;
	unsigned int heightValidate;
}status;
struct {
	unsigned int widthValidated: 1;
	unsigned int heightValidated: 1;
}status2;

int main(void){
	unsigned short i,j;
	i=13;
	j=i<<2;
	printf("i is %d\n",i);
	printf("j is %d\n",j);
	j=i>>2;
	printf("j is %d\n",j);

	printf("Memory size occupied by status: %d\n",sizeof(status));
	printf("Memory size occupied by status2: %d\n",sizeof(status2));

	return 0;

}
