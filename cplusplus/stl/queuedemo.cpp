#include<iostream>
#include<queue>
using namespace std;
int main(){
	queue<int> q;
	for(int i =0;i<10;i++){
		q.push(i);
	}
	cout<<q.front()<<" "<<q.back()<<endl;
	cout<<q.empty()<<" "<<q.size()<<endl;
	q.pop();
	cout<<q.front()<<endl;
	q.pop();
	cout<<q.front()<<endl;
	cout<<q.back()<<endl;
	q.push(852);
	cout<<q.back()<<endl;
	return 0;

}
