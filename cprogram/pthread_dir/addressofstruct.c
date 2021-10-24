#include<stdio.h>
void main(void){
	struct student{
		int age;
		char* sex;
	} stu;
	stu.age=17;
	stu.sex="F";

	printf("%x\n",stu);
	printf("%d\n",stu);
	printf("%p\n",stu);
	printf("the &stu is 0x%x\n",&stu);
}
