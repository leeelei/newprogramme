#include "stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<error.h>

int main(int argc,char** argv[]){
	FILE* fp;
	stack s;
	char c;
	char ctmp;


	if(argc != 2){
		printf("Usage: %s <filename>\n",argv[0]);
		exit(0);
	}


	fp=fopen(argv[1],"r");
	if(fp ==NULL){
		printf("fopen\n");
		exit(1);
	}

	s=create_stack(10);
	c=fgetc(fp);
	while(c != EOF){
		switch(c){
		
			case '(':
				push(c,s);
				break;
			case ')':
				ctmp=top_and_pop(s);
				if(ctmp !='(')
					printf("not match!\n");
				break;
			case '{':
				push(c,s);
				break;
			case '}':
				ctmp=top_and_pop(s);
				if(ctmp !='{')
					printf("not match!\n");
				break;
			case '[':
				push(c,s);
				break;
			case ']':
				ctmp=top_and_pop(s);
				if(ctmp !='[')
					printf("not match!\n");
				break;

		}
		c=fgetc(fp);
	}
	if(is_empty(s))
		printf("match\n");
	else
		printf("not match\n");
}
