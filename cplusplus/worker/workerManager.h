#pragma once   //避免头文件被重复包含，当然也可以使用#ifndef...#define...#endif 的方式，它支持跨平台
#include<iostream>
#include<cstring>
#include "worker.h"
using namespace std;

class WorkerManager{
	public:

		WorkerManager(); //constructor
		void Show_Menu();
		void exitSystem();
		void Add_Emp();
		void save();
		~WorkerManager(); //destructor
		int m_EmpNum;
		Worker** m_EmpArray;
};
