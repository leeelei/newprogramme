#include<iostream>
#include<stack>
using namespace std;
int main(){
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	cout<<s.top()<<endl;

	s.pop();
	cout<<s.top()<<endl;

	s.push(23);
	cout<<s.top()<<endl;
	cout<<"---------------------"<<endl;
	while(!s.empty()){
//		cout<<s.size()<<endl;
		cout<<s.top()<<endl;
		s.pop();
	}
	return 0;
}
