#include<iostream>
#include<pthread.h>
using namespace std;
#define NUM_THREADS 5
void* say_hello(void* arg){
	cout<<"Hello Runoob!"<<endl;
	return 0;
}

int main(){
	pthread_t tid[NUM_THREADS];
	for(int i=0;i<NUM_THREADS;i++){
		int ret=pthread_create(&tid[i],NULL,say_hello,NULL);
		if(ret!=0)
			cout<<"ptread_create error: error_code="<<ret<<endl;
	}
	pthread_exit(NULL);
}
