#include<stdio.h>
#include<stddef.h>
struct address{
	char name[50];
	char street[50];
	int phone;
	char sex;
};

typedef struct {
    size_t      len;   //字符串长度
    char     *data;  //指向字符串的指针
} ngx_str_t;

typedef struct {
    ngx_str_t  ed;
} ngx_http_echo_loc_conf_t;


int main(){
	printf("the offset of name of address structure =%d bytes.\n ",offsetof(struct address,name));
	printf("the offset of street of address structure =%d bytes.\n ",offsetof(struct address,street));
	printf("the offset of phone of address structure =%d bytes.\n ",offsetof(struct address,phone));
	printf("the offset of sex of address structure =%d bytes.\n ",offsetof(struct address,sex));
	
	printf("the size_t is %d\n",sizeof(size_t));
	printf("the char*  is %d\n",sizeof(char* ));
	printf("the ngx_http_echo_loc_conf_t is %d\n",sizeof(ngx_http_echo_loc_conf_t));
	return 0;
}
