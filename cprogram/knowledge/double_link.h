#ifndef _DOUBLE_LINK_H
#define _DOUBLE_LINK_H
typedef struct tag_node{
	struct tag_node* prev;
	struct tag_node* next;
	void* p;
}node;

//create
extern int create_dlink();
extern int destroy_dlink();
extern int dlink_is_empty();
extern int dlink_size();
extern int dlink_size();

//get link information
extern void* dlink_get(int index);
extern void* dlink_get_first();
extern void* dlink_get_last();
//insert
extern int dlink_insert(int index,void* pval);
extern int dlink_insert_first(void* pval);
extern int dlink_insert_last(void* pval);

//delete
extern int dlink_delete(int index);
extern int dlink_delete_first();
extern int dlink_delete_last();
#endif
