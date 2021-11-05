#include<stdio.h>
#include "bstree.h"
static Node* create_bstree_node(Type key,Node* parent,Node* left,Node* right){
	Node* p;
	if((p=(Node*)malloc(sizeof(Node)))==NULL)
		return NULL;
	p->key=key;
	p->left=left;
	p->right=right;
	p->parent=parent;
	return p;
}

void preorder_bstree(BSTree tree){
	if(tree != NULL){
		printf("%d ",tree->key);
		preorder_bstree(tree->left);
		preorder_bstree(tree->right);
	}
}
void inorder_bstree(BSTree tree){
	if(tree != NULL){
		inorder_bstree(tree->left);
		printf("%d ",tree->key);
		inorder_bstree(tree->right);
	}
}
void postorder_bstree(BSTree tree){
	if(tree != NULL){
		postorder_bstree(tree->left);
		postorder_bstree(tree->right);
		printf("%d ",tree->key);
	}
}


Node* bstree_search(BSTree x,Type key){
	if(x==NULL || x->key==key)
		return x;
	if(key < x->key)
		bstree_search(x->left,key);
	else
		bstree_search(x->right,key);
}


Node* iterative_bstree_search(BSTree x,Type key){
	while((x!=NULL) && (x->key !=key)){
		if(key <x->key)
			x=x->left;
		else
			x=x->right;
	}
	return x;
}

static Node* bstree_insert(BSTree tree,Node* z){
	Node* y=NULL;
	Node* x=tree;
	while(x!=NULL){
		y=x;
		if(z->key <x->key)
			x=x->left;
		else
			x=x->right;
	}
	z->parent=y;
	if(y==NULL)
		tree=z;
	else if(z->key <y->key)
		y->left=z;
	else
		y->right=z;
	return tree;
}
Node* insert_bstree(BSTree tree ,Type key){
	Node* z;
	if((z=create_bstree_node(key,NULL,NULL,NULL))==NULL)
		return tree;
	return bstree_insert(tree,z);
}


void print_bstree(BSTree tree,Type key,int direction){
	if(tree !=NULL){
		if(direction ==0)
			printf("%2d is root \n",tree->key);
		else
			printf("%2d is %2d's %6s child\n",tree->key,key,direction == 1 ? "right" : "left");
		print_bstree(tree->left,tree->key,-1);
		print_bstree(tree->right,tree->key,1);
	}
}
