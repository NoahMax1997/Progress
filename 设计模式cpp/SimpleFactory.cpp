#include <iostream>
using namespace std;
class Product{
	public:
		virtual double getArea();
//		double getArea(); //非虚函数继承无法通过基类访问成员子类函数 
}; 
double Product::getArea(){
	cout<<"Product"<<endl;
	return 0;
}
class ConcreteProduct1: public Product{
	private:
		double getArea(){
			cout<<"ConcreteProduct1"<<endl;
			return 0;
		}	
};
class ConcreteProduct2: public Product{
	public:
		double getArea(){
			cout<<"ConcreteProduct2"<<endl;
			return 0;
		}
};
class SimpleFactory{
	Product* CreateProductByType(int type){
		Product* ret;
		if(type==1){
			ret=new ConcreteProduct1(); 
		}else if(type==2){
			ret=new ConcreteProduct2(); 
		}
		return ret;
	}
}; 
int main(){
	Product* p=new ConcreteProduct1();
	p->getArea();
	p=new ConcreteProduct2();
	p->getArea();
	return 0;
} 
