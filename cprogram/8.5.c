#include<stdio.h>
#include<unistd.h>
int main(void){
	FILE *fp;
	int pid;
	char msg1[]="Testing 1 2 3 ..\n";
	char msg2[]="Hello,hello\n";
	if((fp=fopen("testfile2","w"))==NULL)
		return 0;
	fprintf(fp,"%s",msg1);
	fprintf(fp,"%s","stranger!\n");
	fprintf(fp,"Befroe: my pid is %d\n",getpid());
	if((pid=fork())==-1)
		return 0;
	if(pid==0){
		sleep(5);
		//fprintf(fp,"%s","child process writing!!\n");
	}
	fprintf(fp,"%s",msg2);
	fprintf(fp,"After: my pid is %d ,fork() said %d\n",getpid(),pid);
	fclose(fp);
	return 0;
}

	
