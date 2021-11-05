#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
	map<int,string>m;
	m.insert(pair<int,string>(1,"good"));
	m[2]="hello";
	m[3]="gell";
	m.insert(pair<int,string>(4,"a"));
	cout<<m.size()<<endl;


	for(map<int,string>::iterator it=m.begin();it!=m.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}

	cout<<m.count(1)<<endl;

	if(m.find(7)==m.end())
		cout<<"找不到 key值"<<endl;

	m.erase(1);
	if(m.find(1)==m.end())
		cout<<"找不到 key值"<<endl;


	return 0;
}
