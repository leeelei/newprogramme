#include<stdio.h>
#include<malloc.h>
#include "double_link.h"

static node* phead=NULL;
static int count=0;

static node* create_node(void* pval){
	node* pnode=NULL;
	pnode=(node*)malloc(sizeof(node));
	if(!pnode){
		printf("create node error!\n");
		return NULL;
	}

	pnode->prev=pnode->next=pnode;
	pnode->p=pval;
	return pnode;
}

int create_dlink(){
	phead=create_node(NULL);
	if(!phead)
		return -1;
	count=0;
	return 0;
}


int dlink_is_empty(){
	return count==0;
}
int dlink_size(){
	return count;
}
// 获取“双向链表中第index位置的节点”
static node* get_node(int index){
	if(index<0 || index>count){
		printf("%s failed! index out of bound!\n",__func__);
		return NULL;
	}

	if(index<=(count/2)){
		int i=0;
		node* pnode=phead->next;
		while((i++)<index)
			pnode=pnode->next;
		return pnode;
	}

	int j=0;
	int rindex=count-index-1;
	node* rnode=phead->prev;
	while((j++)<rindex)
		rnode=rnode->prev;
	return rnode;
}



static node* get_first_node(){
	return get_node(0);
}
static node* get_last_node(){
	return get_node(count-1);
}

void* dlink_get(int index){
	node* pindex=get_node(index);
	if(!pindex){
		printf("%s failed!\n",__func__);
		return NULL;
	}
	return pindex->p;
}


void* dlink_get_first(){
	return dlink_get(0);
}
void* dlink_get_last(){
	return dlink_get(count-1);
}


int dlink_insert(int index,void* pval){
	//insert the head
	if(index == 0)
		return dlink_insert_first(pval);	

	node* pindex=get_node(index);
	if(!pindex)
		return -1;
	node* pnode=create_node(pval);
	if(!pnode)
		return -1;

	pnode->prev=pindex->prev;
	pnode->next=pindex;
	pindex->prev=pnode;
	pindex->prev->next=pnode;
	count++;
	return 0;
}

int dlink_insert_first(void* pval){
	node* pnode=create_node(pval);
	if(!pnode)
		return -1;
	if(!phead)
		printf("phead is NULL\n");
	pnode->prev=phead;
	pnode->next=phead->next;
	phead->next->prev=pnode;
	phead->next=pnode;
	count++;
	return 0;
}



