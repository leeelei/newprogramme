#include<iostream>
using namespace std;
class Box{
	public:
		double getVolume(void){
			return length*breadth*height;
		}
		void setLength(double len){
			length=len;
		}
		void setBreadth(double bre){
			breadth=bre;
		}
		void setHeight(double hei){
			height=hei;
		}

		Box operator+(const Box& b){
			Box box; //temporary object to store the sum of +
			box.length=this->length+b.length;
			box.breadth=this->breadth+b.breadth;
			box.height=this->height+b.height;
			return box; //return temporary object
		}
	private:
		double length;
		double breadth;
		double height;
};
int main(){
	Box box1;
	Box box2;
	Box box3;
	double volume=1.0;

	box1.setLength(6.0);
	box1.setBreadth(7.0);
	box1.setHeight(5.0);

	box2.setLength(12.0);
	box2.setBreadth(13.0);
	box2.setHeight(10.0);

	volume=box1.getVolume();
	cout<<"Volume of box1 : "<<volume<<endl;

	volume=box2.getVolume();
	cout<<"Volume of box2 : "<<volume<<endl;


	box3=box1+box2;

	volume=box3.getVolume();
	cout<<"Volume of box3 : "<<volume<<endl;

	return 0;
}
