#include<iostream>
#include<string>
using namespace std;
class MakeDrink{
public:
	virtual void boil()=0;
	virtual void brew()=0;
	virtual void pour()=0;
	virtual void add_flavour()=0;

	void makedrink(){
		boil();
		brew();
		pour();
		add_flavour();
	}
};


class coffee:public MakeDrink{
	public:
		void boil(){
			cout<<"煮农夫山泉!"<<endl;
		}
		void brew(){
			cout<<"冲泡咖啡!"<<endl;
		}
		void pour(){
			cout<<"将咖啡倒入杯中!"<<endl;
		}
		void add_flavour(){
			cout<<"加入牛奶!"<<endl;
		}
};


class tea:public MakeDrink{
	public:
		void boil(){
			cout<<"煮自来水!"<<endl;
		}
		void brew(){
			cout<<"冲泡茶叶!"<<endl;
		}
		void pour(){
			cout<<"将茶水倒入杯中!"<<endl;
		}
		void add_flavour(){
			cout<<"加入枸杞!"<<endl;
		}
		
};
void Make_Drink(MakeDrink& drink){
	drink.makedrink();
}
void Make_Drink2(MakeDrink* drink){
	drink->makedrink();
	delete drink;
}

int main(){
	cout<<"--------------"<<endl;
	//pointer call
	Make_Drink2(new coffee);
	Make_Drink2(new tea);
	cout<<"--------------"<<endl;
	//references call
	coffee coco;
	Make_Drink(coco);
	tea cha;
	Make_Drink(cha);
	return 0;
}
