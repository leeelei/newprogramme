#include<stdio.h>
#include "double_link.h"
void int_test(){
	int iarr[4]={10,20,30,40};
	printf("\n----%s----\n", __func__);
	create_dlink();

	dlink_insert(0,&iarr[0]);
	dlink_insert(0,&iarr[1]);
	dlink_insert(0,&iarr[2]);


	printf("dlink_is_empty()=%d\n",dlink_is_empty());
	printf("dlink_size()=%d\n",dlink_size());


}
int main(){
	int_test();
}
