#include<stdio.h>
#include "DoubleList.h"
int main(void){
	Node* head=NULL;
	head=initNode(head);
	display(head);
	printf("the prior of fourth node is: %d\n",head->next->next->next->prior->data);
	return 0;
}
