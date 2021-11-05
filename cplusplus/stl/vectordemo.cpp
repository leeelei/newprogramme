#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	vector<int> a(10);
	vector<int>v(10,1);
	vector<int> obj;

	obj.push_back(1);
	obj.push_back(5);
	obj.push_back(2);
	obj.push_back(3);

	for(vector<int>::iterator it=obj.begin();it!=obj.end();it++)
		cout<<*(it)<<" ";
	cout<< endl;

	for(int i=0;i<obj.size();i++)
		cout<<obj[i]<<" ";
	obj.pop_back();
	cout<<endl;

	for(int i=0;i<obj.size();i++)
		cout<<obj[i]<<" ";
	cout<<endl;


	cout<<obj.front()<<" "<<obj.back()<<endl;
	cout<<obj.at(1)<<endl;

	sort(obj.begin(),obj.end());
	for(int i=0;i<obj.size();i++)
		cout<<obj[i]<<" ";
	cout<<endl;
	
	reverse(obj.begin(),obj.end());
	for(int i=0;i<obj.size();i++)
		cout<<obj[i]<<" ";
	cout<<endl;


	vector<vector<int>>o(10);
	for(int i=0;i<o.size();i++){
		o[i].resize(5);
	}

	for(int i=0;i<o.size();i++){
		for(int j=0;j<o[i].size();j++)
			cout<<o[i][j]<<" ";
		cout<<endl;
	}
	
	return 0;
}
