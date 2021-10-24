/*include head file*/
#include<ngx_core.h>
#include<ngx_http.h>
#include<ngx_config.h>

/*hadler function declaration*/
static char* set(ngx_conf_t* ,ngx_command_t*,void*);
static ngx_int_t handler(ngx_http_request_t*);

/*command register and it is a array*/
static ngx_command_t test_commands[]={
	{ngx_string("test"),
	NGX_HTTP_LOC_CONF|NGX_CONF_NOARGS,
	set,
	NGX_HTTP_LOC_CONF_OFFSET,
	0,
	NULL},
	ngx_null_command
};

/*the structure of callback funtion*/
static ngx_http_module_t test_ctx={
	NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL
};

/*another structer for letting nginx know what the module is about*/
ngx_module_t ngx_http_test_module={
	NGX_MODULE_V1,
	&test_ctx,
	test_commands,
	NGX_HTTP_MODULE,
	NULL,NULL,NULL,NULL,NULL,NULL,NULL,
	NGX_MODULE_V1_PADDING
};


/*the compliment of set above*/
static char* set(ngx_conf_t *cf,ngx_command_t* cmd,void *conf){
	ngx_http_core_loc_conf_t *corecf;
	corecf=ngx_http_conf_get_module_loc_conf(cf,ngx_http_core_module);
	corecf->handler=handler;
	return NGX_CONF_OK;
}

static ngx_int_t handler(ngx_http_request_t* req){
	u_char html[1024]="<h1>This is a Test page already!!</h1>";
	int len=sizeof(html)-1;
	req->headers_out.status=200;
	req->headers_out.content_length_n=len;
	ngx_str_set(&req->headers_out.content_type,"text/html");
	ngx_http_send_header(req);

	ngx_buf_t* b;
	b=ngx_pcalloc(req->pool,sizeof(ngx_buf_t));
	b->pos=html;
	b->last=html+len;
	b->memory=1;
	b->last_buf=1;
	ngx_chain_t out;
	out.buf=b;
	out.next=NULL;
	return ngx_http_output_filter(req,&out);
}
