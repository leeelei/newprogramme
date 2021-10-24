#include<stdio.h>
typedef char* QElemType;

//the structure of queue node
typedef struct QNode{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

//structure of queue
typedef struct Link_queue{
	QueuePtr front;  // the front of queue
	QueuePtr rear;   // the end of queue
}LinkQueue;

typedef int Status;
#define ERR_OK 0
#define ERR_NO 1

//the operation of inserting
Status Enqueue(LinkQueue* Q,QElemType e){
	QueuePtr newNode=(QueuePtr)malloc(sizeof(QNode));
	size_t len=strlen(e);
	newNode->data=(QElemType)malloc(len+2*sizeof(char)); //allocate memory for node data;
	int i=0;
	for(i=0;i<len;i++){
		newNode->data[i]=e[i];
	}
	newNode->data[len]='\0';
	newNode->next=NULL;

	Q->rear->next=newNode;
	Q->rear=newNode;
	return ERR_OK;
}

//remove data from queue
Status DeQueue(LinkQueue* Q,QElemType* e){
	QueuePtr p;
	p=Q->front->next;
	size_t len=strlen(p->data);
	*e=(QElemType)malloc(len+2*sizeof(char));
	
	int i=0;
	for(i=0;i<len;i++){
		(*e)[i]=p->data[i];	
	}	
	(*e)[len]='\0';
	Q->front->next=p->next;

	if(Q->rear==p)
		Q->rear=Q->front;

	free(p->data);
	free(p);
	return ERR_OK;
}

int main(void){
	QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
	s->data=0;
	s->next=NULL;

	LinkQueue linkqueue;
	linkqueue.front=s;
	linkqueue.rear=s;
	Enqueue(&linkqueue,"hello1");
	Enqueue(&linkqueue,"hello2");
	Enqueue(&linkqueue,"hello3");
	Enqueue(&linkqueue,"hello4");
	Enqueue(&linkqueue,"hello5");
	

	QElemType value;
	QElemType value1;
	QElemType value2;
	QElemType value3;


	DeQueue(&linkqueue,&value);
	printf("value=%s\n",value);

	DeQueue(&linkqueue,&value1);
	printf("value1=%s\n",value1);

	DeQueue(&linkqueue,&value2);
	printf("value2=%s\n",value2);

	DeQueue(&linkqueue,&value3);
	printf("value3=%s\n",value3);


	getchar();

}
