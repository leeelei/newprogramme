#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}Node;

typedef struct tree{
	Node* root;
}Tree;

void insert(Tree* tree,int value){
	Node* node=(Node*)malloc(sizeof(Node));
	node->data=value;
	node->left=NULL;
	node->right=NULL;

	if(tree->root==NULL)
		tree->root=node;
	else{
		Node* temp=tree->root;
		while(temp !=NULL){
			if(value < temp->data){
				if(temp->left ==NULL){
					temp->left=node;
					return ;
				}else{
					temp=temp->left;
				}
			}else{
				if(temp->right ==NULL){
					temp->right=node;
					return;
				}else{
					temp=temp->right;
				}
			}

		}
	
	}

}

void traverse(Node* node){
	if(node !=NULL){
		traverse(node->left);
		printf("%d\n",node->data);
		traverse(node->right);
	}
}

void distroy_tree(Node* node){
	if(node !=NULL){
		distroy_tree(node->left);
		distroy_tree(node->right);
		printf("free node: %d\n",node->data);
		free(node);
		node=NULL;
	}
}


int main(){
	int i=0;
	Tree tree;
	tree.root=NULL;
	int n;
	printf("input total num: \n");

	scanf("%d",&n);
	for(i=0;i<n;i++){
		int temp;
		scanf("%d",&temp);
		insert(&tree,temp);
	}

	traverse(tree.root);
	distroy_tree(tree.root);
	return 0;
}
