#include<stdio.h>
#include<unistd.h>
int main(int argc,char* argv[]){
	int ch;
	//this is a global variables,other global variables are char* oprarg,int optind,int optopt
	opterr=0;
	while((ch=getopt(argc,argv,"a:bcde"))!=-1){
		switch(ch){
			case 'a':
				printf("option a:%s\n",optarg);
				break;
			case 'b':
				printf("option b :b\n");
				break;
			default:
				printf("other option: %c\n",ch);
		}
	}
	printf("optopt+%c\n",optopt);
}
