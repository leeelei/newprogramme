#include<stdio.h>
typedef struct{
	char c1;
	short s;
	char c2;
	int i;
}T_FOO;
typedef struct{
	char a;
	int i;
	char b;
	char c;
}tTestEntry1;
typedef struct A{
	int a;
	char b;
	short c;
}A_t;
void main(void){
	T_FOO a;
	printf("c1-> %d\n",(unsigned int)(void*)&a.c1-(unsigned int)(void*)&a);
	printf("s-> %d\n",(unsigned int)(void*)&a.s-(unsigned int)(void*)&a);
	printf("c2-> %d\n",(unsigned int)(void*)&a.c2-(unsigned int)(void*)&a);
	printf("s-> %d\n",(unsigned int)(void*)&a.i-(unsigned int)(void*)&a);


	printf("c1->0x%x\n",&a.c1);
	printf("s->0x%x\n",&a.s);
	printf("c2->0x%x\n",&a.c2);
	printf("i->0x%x\n",&a.i);

	printf("the length osf A_t is %d\n",sizeof(A_t));


//	printf("the size of tTestEntry1 %d\n",sizeof(tTestEntry1));
//	printf("The address of a is 0x%x\n",&(test.a));
//	printf("The address of a is 0x%x\n",&(test.i));
//	printf("The address of a is 0x%x\n",&(test.b));
//	printf("The address of a is 0x%x\n",&(test.c));

}
