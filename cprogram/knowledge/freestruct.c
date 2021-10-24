#include<stdio.h>
#include<string.h>
struct stuff{
	char* home;
	int num;
	char name[10];
};

int main(void){
	struct stuff* tom=(struct stuff*)malloc(sizeof(struct stuff));
	tom->home="london";
	tom->num=201;
	strcpy(tom->name,"tome");
	char* p1=tom->home;
	char* p2=tom->name;

	printf("home=%s pointer of home %p name=%s\n",tom->home,tom->home,tom->name);
	free(tom);
	printf("home=%s pointer of home %p name=%s\n",p1,p1,p2);
	return 0;

}
