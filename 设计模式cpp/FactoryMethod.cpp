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
class Factory{
	public:
		virtual Product* factoryMethod()=0;
		void doSomething(){
			Product* p=factoryMethod();
			cout<<"Factory do something"<<endl;
			p->getArea();
		}
}; 

class ConcreteFactory1: public Factory{
	private:
		Product* factoryMethod(){
			return new ConcreteProduct1();
		}
			
};
class ConcreteFactory2: public Factory{
	public:
		Product* factoryMethod(){
			return new ConcreteProduct2();
		}
		
};

int main(){
	Factory* f=new ConcreteFactory1();
	f->doSomething();
	f=new ConcreteFactory2();
	f->doSomething();
	return 0;
} 
