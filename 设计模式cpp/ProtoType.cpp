#include <iostream>
#include <string>
using namespace std;
class ProtoType{
	public:
 	virtual ProtoType* clone()=0;
 	virtual void show()=0;
};
class ConcreteProtoType:public ProtoType{
	private: string filed;
	public:
		ConcreteProtoType(string filed):filed(filed){
		};
		ProtoType* clone(){
			return new ConcreteProtoType(filed);
		}
		void show(){
			cout<<filed<<endl;
		}
};
int main(){
	ProtoType* p=new ConcreteProtoType("1234");
	ProtoType* p2=p->clone();
	p->show();
	p2->show();
	return 0;
} 
