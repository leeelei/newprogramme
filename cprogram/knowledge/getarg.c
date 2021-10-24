#include<stdio.h>
int main(int argc,char** argv){
	int i=0;
	char* p;
	for(i=1;i<argc;i++){
		p=argv[i];
//		printf("argument is %s \n",argv[i]);
		if(*p++ != '-'){
			printf("invalide option: \"%s\"\n",argv[i]);
			return 1;
		}
		while(*p){
			switch(*p++){
				case '?':
				case 'h':
					printf("this is mark option\n");
					break;
				case 'v':
					printf("the version is new\n");
					break;
				case 'V':
					printf("the version is old\n");
					break;
				case 't':
					printf("this is test\n");
					break;
				case 'q':
					printf("this is quit\n");
					break;
				default :
					printf("there is no argument\n");
					break;

			}
		}
	}
	return 0;

}
