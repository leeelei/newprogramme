#include<fstream>
#include"workerManager.h"
#include"employee.h"
#include"worker.h"
#define FILENAME "empFile.txt"
WorkerManager::WorkerManager(){
	this->m_EmpNum = 0;
	this->m_EmpArray=NULL;
}
WorkerManager::~WorkerManager(){
	if(this->m_EmpArray!=NULL)
		delete[] this->m_EmpArray;
}

void WorkerManager::Show_Menu(){
	cout<< "*****************************************************************"<<endl;
	cout<< "***********   欢迎使用职工管理系统！  ***************************"<<endl;
	cout<< "****************   0.退出管理程序     ***************************"<<endl;
	cout<< "****************   1.增加职工信息     ***************************"<<endl;
	cout<< "****************   2.显示职工信息     ***************************"<<endl;
	cout<< "****************   3.删除离职职工     ***************************"<<endl;
	cout<< "****************   4.修改职工信息     ***************************"<<endl;
	cout<< "****************   5.查找职工信息     ***************************"<<endl;
	cout<< "****************   6.按照编号排序     ***************************"<<endl;
	cout<< "****************   7.清空所有文档     ***************************"<<endl;
	cout<< "*****************************************************************"<<endl;	
	cout<<endl;
}
void WorkerManager::exitSystem(){
	cout<<"欢迎下次使用"<<endl;
	exit(0);
}
void WorkerManager::Add_Emp(){
	cout<<"请输入增加职工数量："<<endl;
	int addNum=0;
	cin>>addNum;
	if(addNum>0){
		int newSize=this->m_EmpNum+addNum;
		Worker** newSpace=new Worker*[newSize];
		if(this->m_EmpArray !=NULL){
			for(int i=0;i<this->m_EmpNum;i++){
				newSpace[i]=this->m_EmpArray[i];
			}
		}
		//input new data
		for(int i=0;i<addNum;i++){
			int id;
			string name;
			int dSelect;
			cout<<"请输入第 " << i + 1 << " 个新职工编号："<<endl;
			cin>>id;
			cout<<"请输入第 " << i + 1 << " 个新职工姓名："<<endl;
			cin>>name;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin>>dSelect;

			Worker* worker=NULL;
			switch(dSelect){
				case 1:
					worker=new Employee(id,name,1);
					break;
				case 2:
				//	worker=new Manager(id,name,2);
					break;
				case 3:
				//	worker=new Boss(id,name,3);
					break;
				default:
					break;

			}
			newSpace[this->m_EmpNum+i]=worker;
		}
		delete[] this->m_EmpArray;//释放原有空间
		this->m_EmpArray=newSpace;
		this->m_EmpNum=newSize;
		this->save();
		cout<<"成功添加"<<addNum<<"名新职工！"<<endl;

	}
	else
		cout<<"输入有误"<<endl;
	
}
void WorkerManager::save(){
	char c_name[20];
	fstream ofs;
	ofs.open(FILENAME,ios::out);
	for(int i=0;i<this->m_EmpNum;i++){
		strcpy(c_name,this->m_EmpArray[i]->m_Name.c_str());
		ofs<<this->m_EmpArray[i]->m_Id<<" "<<c_name	<<"  "<<this->m_EmpArray[i]->m_DeptId<<endl;
	}
	ofs.close();
}
int main(){
	WorkerManager wm;
	int choice=0;
	while(true){
		wm.Show_Menu();
		cout<<"请输入您的选择:"<<endl;
		cin>>choice;
//		choice=cin.get();
//		cout<<"choice is "<<choice<<endl;
		switch(choice){
			case 0:
				cout<<"入错误，请从选项中选择!"<<endl;
				wm.exitSystem();
				break;
			case 1:
				wm.Add_Emp();
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			default:
				cout<<"输入错误，请从选项中选择!"<<endl;
				break;
		}
	}
	
	/*
	Worker* worker=NULL;
	worker=new Employee(1,"张三",1);
	worker->showInfo();
	delete worker;

	worker=new Employee(2,"李四",2);
	worker->showInfo();
	delete worker;

	worker=new Employee(3,"王五",3);
	worker->showInfo();
	delete worker;

	*/
	wm.exitSystem();
	return 0;
}
