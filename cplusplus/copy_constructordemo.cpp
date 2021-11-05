#include<iostream>
using namespace std;
class Line{
	public:
		int getLength(void);
		Line(int len);
		Line(const Line& obj);
		~Line();

	private:
		int *ptr;
};

Line::Line(int len){
	cout<<"调用构造函数"<<endl;
	ptr=new int; //strange form,but it is cool,declare a memory space
	*ptr=len;
}
Line::Line(const Line& obj){
	cout<<"调用拷贝构造函数并为指针 ptr 分配内存"<<endl;
	ptr=new int;
	*ptr=*obj.ptr; // copy the value of parameter
}

Line::~Line(){
	cout<<"释放内存"<<endl;
	delete ptr;
}

int Line::getLength(void){
	return *ptr;
}

//outside function
void display(Line obj){ // here,called the copy constructor.
	cout<<"the size of line: "<<obj.getLength()<<endl;
}


int main(){
	Line line(10);
	display(line);
	return 0;
}



