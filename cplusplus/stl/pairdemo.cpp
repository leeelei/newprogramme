#include<iostream>
using namespace std;
pair<int,int>func(){
	int height=3;
	int weight=4;
	return pair<int,int>(3,4);
}
int main(){
	pair<int,int> p=func();
	cout<<p.first<<" "<<p.second<<endl;
	return 0;
}
