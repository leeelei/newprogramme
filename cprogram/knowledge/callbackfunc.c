#include<stdio.h>
#include<stdlib.h>

//define the callback funciton
int add(int a,int b){
	return a+b;
}
int sub(int a, int b){
	return a-b;
}
//define the function pointer type
typedef int (*fcb_func)(int a,int b);

//define the C struct with class, or  with function inside the struct.
typedef struct mydata{
	int a,b;
	fcb_func fcb;  // the pointer type 
}mydata_t;

// create the struct  with class
mydata_t* mydata_create(fcb_func out_fcb){
	mydata_t* data=(mydata_t*)malloc(sizeof(mydata_t));
	data->fcb=out_fcb;
	data->a=0;
	data->b=0;
	return data;
}
void mydata_release(mydata_t* data){
	free(data);
}
void mydata_operate(mydata_t* data){
	int c=data->fcb(data->a,data->b);
	printf("mydata inner operate %d\n",c);
}
int main(void){
	mydata_t *data=mydata_create(add);
	data->a=10;
	data->b=3;

	mydata_operate(data);


	data->fcb=sub;//change the function int the data struct
	mydata_operate(data);
	return 0;

}
