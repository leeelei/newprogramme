#include "list.h"
List* CreateList(void){
	List* p;
	EleType data=0;
	p=(List*)malloc(sizeof(List));

	if(!p)
		return 0;
	p->head=NewChainNode(data);
	if(!p->head){
		free(p);
		return 0;
	}
	return p;
}
void DestroyList(List* lp){
	ClearList(lp);
	free(lp->head);
	free(lp);
}
void ClearList(List* lp){
	while(ListDelete(lp,1));
}
int ListAppend(List* lp,EleType data){
	ChainNode* p;
	ChainNode* newp;
	newp=NewChainNode(data);
	if(!newp)
		return 0;
	for(p=lp->head;p->next;p=p->next);
	p->next=newp;
	return 1;
}
int ListInsert(List* lp,int n,EleType data){
	ChainNode* p;
	ChainNode* newp;
	p=GetAddr(lp,n-1);
	if(!p)
		return 0;
	newp=NewChainNode(data);
	newp->next=p->next;
	p->next=newp;
	return 1;
}

int ListDelete(List* lp,int n){
	ChainNode* p;
	ChainNode* p1;
	if(!lp->head->next)
		return 0;
	p=GetAddr(lp,n-1);
	if(!(p&&p->next))
		return 0;
	p1=p->next;
	p->next=p->next->next;
	free(p1);
	return 1;
}
int GetElement(List* lp,int n,EleType* data){
	ChainNode* p;
	p=GetAddr(lp,n);
	if(!p)
		return 0;
	*data=p->data;
	return 1;
}

int TraverseList(List* lp,int (*f)(EleType*)){
	ChainNode* p;
	int a=0;
	for(p=lp->head->next;p;p=p->next){
		if(!f(&(p->data)))
			return a++;
	}
	return 0;
}
ChainNode* NewChainNode(EleType data){
	ChainNode* p;
	p=(ChainNode*)malloc(sizeof(ChainNode));
	if(!p)
		return 0;
	p->data=data;
	p->next=0;
	return p;
}
ChainNode* GetAddr(List* lp,int n){
	ChainNode* p;
	int a;
	if(n<0)
		return 0;
	p=lp->head;
	a=0;
	while(p&&a<n){
		p=p->next;
		a++;
	}
	return p;
}


