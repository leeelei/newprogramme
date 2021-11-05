#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include<iostream>
#include<string>
#include "worker.h"
using namespace std;

class Employee:public Worker
{
	public:
	Employee(int id,string name,int dId);
	//show personal information
	virtual void showInfo();
	//get the name of department
	virtual string getDeptName();
};
#endif
