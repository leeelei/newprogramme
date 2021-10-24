#include "DoubleList.h"
#include<stdio.h>
Node* initNode(Node* head){
	head=(Node*)malloc(sizeof(Node));
	//init the node
	head->prior=NULL;
	head->next=NULL;
	head->data=1;
	Node* list=head;

	for(int i=2;i<=5;i++){
		Node* body=(Node*)malloc(sizeof(Node));
		body->prior=NULL;
		body->next=NULL;
		body->data=i;

		list->next=body;
		body->prior=list;

		list=list->next;
	}

	return head;
}
void display(Node* head){
	Node* temp=head;
	while(temp){
		if(temp->next==NULL){
			printf("%d\n",temp->data);
		}else{
			printf("%d<->",temp->data);	
		}
		temp=temp->next;
	}
}
