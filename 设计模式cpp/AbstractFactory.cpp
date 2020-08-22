#include <iostream>
using namespace std;
class AbstractProductA{
	public:
		virtual double getArea()=0;
}; 
class AbstractProductB{
	public:
		virtual double getArea()=0;
};
class ProductA1:public  AbstractProductA{
	public:
		double getArea(){
			cout<<"ProductA1"<<endl;
		}
};
class ProductA2:public  AbstractProductA{
	public:
		double getArea(){
			cout<<"ProductA2"<<endl;
		}
};
class ProductB1:public  AbstractProductB{
	public:
		double getArea(){
			cout<<"ProductB1"<<endl;
		}
};
class ProductB2:public  AbstractProductB{
	public:
		double getArea(){
			cout<<"ProductB2"<<endl;
		}
};

class Factory{
	public:
		virtual AbstractProductA* createAbstractProductA()=0;
		virtual AbstractProductB* createAbstractProductB()=0;
}; 
class SubFactory1:public Factory{
	public: ProductA1* createAbstractProductA(){
		return new ProductA1();
	}
	public: ProductB1* createAbstractProductB(){
		return new ProductB1();
	}
};
class SubFactory2:public Factory{
	public: ProductA2* createAbstractProductA(){
		return new ProductA2();
	}
	public: ProductB2* createAbstractProductB(){
		return new ProductB2();
	}
};
int main(){
	Factory* f=new SubFactory1();
	f->createAbstractProductA()->getArea();
	return 0;
} 
