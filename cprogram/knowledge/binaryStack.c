/******************************************************
 * 做一个入栈操作，把一串二进制数字压入栈里
 * 之后应该是一个出栈操作，包括在一个大循环中
 * 第一个出栈的乘以2^0,第二个出栈的乘以2^1.....以此类推
 * 把每个二次幂的结果求和就得到十进制
 *
 * Created Time: 2021年10月06日 星期三 13时28分30秒
 * Author:Lee
 * **************************************************/

#include "stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){
	stack st;
	st=create_stack(100);
	if(st == NULL)
		printf("create_stack!!\n");
	int c;
	printf("Please input the binary numbers: ");
	while((c=getchar()) != '\n'){
		putchar(c);
		if(c != '\n'){
			if(isspace(c))
				continue;
			push(c,st);
		}
	}
	printf("the top of stack is %d\n",st->top_of_stack);

	int sum=0;
	int temp=0;
	for(size_t i=0;!is_empty(st);i++){
		temp=top_and_pop(st);	
		sum=sum+(temp-48)*pow(2,i);
	}
	printf("the decimal is %d\n",sum);
	return 0;
}
