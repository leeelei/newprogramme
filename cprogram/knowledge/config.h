#include<stdio.h>
#include<stdlib.h>
struct conf_info{
	const char* name;
	void* object;
};

typedef struct conf_info Cconf_info;

extern void trim(char* );
extern struct conf_info* lookup_keyword(char* );
extern void apply_command(Cconf_info* ,char*);
extern void parse(FILE*);
