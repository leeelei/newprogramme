#include<stdio.h>
#include "list.h"
char a[20]="hello world!";
void showlsit(List*);
int putelement(EleType*);
int main(void){
	List* lp;
	int n;
	lp=CreateList();
	if(!lp){
		printf("Create?\n");
		return ;
	}
	for(n=0;a[n];n++)
		ListAppend(lp,a[n]);
	showlist(lp);


	ListInsert(lp,1,'h');
	showlist(lp);
	ListInsert(lp,8,'a');
	showlist(lp);

	ListDelete(lp,1);
	showlist(lp);
	ListDelete(lp,7);
	showlist(lp);
	return 0;
}

void showlist(List* lp){
	TraverseList(lp,putelement);
	printf("\n");
}
int putelement(EleType* data){
	printf("%c",*data);
	return 1;
}
