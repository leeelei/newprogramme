#include<iostream>
#include<queue>
using namespace std;
int main(){
	priority_queue<int> pq;
	pq.push(2);
	pq.push(1);
	pq.push(50);
	pq.push(8);
	pq.push(5);


	cout<<pq.size()<<endl;
	while(!pq.empty()){
		cout<<pq.top()<<endl;
		pq.pop();
	}

	return 0;

}
