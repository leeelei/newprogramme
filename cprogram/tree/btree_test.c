#include<stdio.h>
#include "bstree.h"
static int arr[]={1,5,4,3,2,6};
#define TBL_SIZE(a) ((sizeof(a))/(sizeof(a[0])))
void main(){
	int i ,ilen;
	BSTree root =NULL;
	printf("=== ADD gradually:");
	ilen=TBL_SIZE(arr);
	for(i=0;i<ilen;i++){
		root=insert_bstree(root,arr[i]);
	}

	printf("\n==preorder_bstree\n");
	preorder_bstree(root);
	printf("\n");
}
