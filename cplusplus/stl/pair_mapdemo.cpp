#include<iostream>
#include<map>
using namespace std;
struct student{
	int height;
	int weight;
};
int main(void){
	map<int,struct student> map1;
	struct student a;
	struct student b;

	map1.insert(pair<int,struct student>(1,a));
	map1.insert(pair<int,struct student>(2,b));
	cout<<map1.size()<<endl;
	return 0;
}
