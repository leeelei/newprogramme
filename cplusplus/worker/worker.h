#ifndef _WORKER_H_
#define _WORKER_H_
#include<iostream>
#include<string>
using namespace std;
class Worker{
	public:
		//show personal informaiton
		virtual void showInfo()=0; //pure virtual function
		//get the name of department
		virtual string getDeptName()=0;

		//the number of employee
		int m_Id;
		//the name of employee
		string m_Name;

		//the number of department
		int m_DeptId;
};


#endif
