#include<unistd.h>
int main(int argc,char* argv[]){
	chdir(argv[1]);
	printf("current working directory: %s\n",getcwd(NULL,NULL));
	return 0;
}	
