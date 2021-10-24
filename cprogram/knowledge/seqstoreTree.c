/*二叉树顺序存储结构实现*/
#include<stdio.h>
#define MAX_SIZE 100
#define OK 1
#define ERROR 0
typedef int Status;
typedef int TElemType;
typedef TElemType SqBiTree[MAX_SIZE];
void initSQBiTree(SqBiTree T){
	for(int i=0;i<MAX_SIZE;i++){
		T[i]=0;
	}
}


Status setNode(SqBiTree T,int i,TElemType e){
	if(T==NULL) 
		return ERROR;
	if(i>=MAX_SIZE)
		return ERROR;
	T[i]=e;
	return OK;
}

Status setLeftChild(SqBiTree T,int i,TElemType e){
	if(T==NULL) 
		return ERROR;
	if(i*2>=MAX_SIZE)
		return ERROR;
	T[i*2]=e;
	return OK;
}

Status setRightChild(SqBiTree T,int i,TElemType e){
	if(T==NULL) 
		return ERROR;
	if(i*2+1>=MAX_SIZE)
		return ERROR;
	T[i*2+1]=e;
	return OK;
}

void printTree(SqBiTree T){
	for(int i =1;i<MAX_SIZE;i++){
		printf("the %dth node is %d\n",i,T[i]);
	}
}

int main(void){
	SqBiTree T;
	initSQBiTree(T);
	setNode(T,1,1);
	setLeftChild(T,1,2);
	setRightChild(T,1,4);

	setLeftChild(T,3,6);
	setRightChild(T,3,7);


	printTree(T);
	return 0;

}


