#include<stdio.h>
enum DAY{
	MON=1,TUE,WED,THU,FRI,SAT,SUN 
};

typedef enum {
    echo_opcode_echo_sync,
    echo_opcode_echo,
    echo_opcode_echo_request_body,
    echo_opcode_echo_sleep,
    echo_opcode_echo_flush,
    echo_opcode_echo_blocking_sleep,
    echo_opcode_echo_reset_timer,
    echo_opcode_echo_before_body,
    echo_opcode_echo_after_body,
    echo_opcode_echo_location_async,
    echo_opcode_echo_location,
    echo_opcode_echo_subrequest_async,
    echo_opcode_echo_subrequest,
    echo_opcode_echo_duplicate,
    echo_opcode_echo_read_request_body,
    echo_opcode_echo_foreach_split,
    echo_opcode_echo_end,
    echo_opcode_echo_abort_parent,
    echo_opcode_echo_exec
} ngx_http_echo_opcode_t;


int main(){
	enum DAY day;
	ngx_http_echo_opcode_t test;
	day=MON;
	test=echo_opcode_echo_exec;
	printf("%d\n",day);
	printf("%d\n",test);
	return 0;
}
