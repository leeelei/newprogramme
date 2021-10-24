#include<stdio.h>
union data{
	int n;
	char ch;
	short m;
};
union wonderfull{
	int x;
	int y;
};

int main(){
	union data a;
	printf("%ld,%ld\n",sizeof(a),sizeof(union data));
	union wonderfull won;
	won.x=1;
	printf("y is %d\n",won.y);
	return 0;
}
