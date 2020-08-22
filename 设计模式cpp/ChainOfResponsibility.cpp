#include <iostream>
using namespace std;
//class AbstractHandle;
enum Level{
	level1,level2,level3
};
class Request{
	private:
		Level level;
		string req_str;
	public:
		Request(Level level,string req_str):level(level),req_str(req_str){
		}
		Level getLevel(){
			return level;
		}
		string toString(){
			cout<<"level:"<<level<<"  ";
			return req_str;
		}
		
};
class AbstractHandler{
	protected:
		AbstractHandler* successor;//next chain
	public:
		AbstractHandler(AbstractHandler* handler){
			this->successor=handler;
		}
		virtual void handleRequest(Request req)=0;
};
class ConcreteHandler1:public AbstractHandler{
	public:
		ConcreteHandler1(AbstractHandler* handler):AbstractHandler(handler){
		}	
		void handleRequest(Request req){
			if(req.getLevel()==level1){
				cout<<"ConcreteHandler1 "<<req.toString()<<endl;
			}else{
				if(this->successor!=NULL){
					this->successor->handleRequest(req);
				}else{
					cout<<"handle out"<<endl;
				}
			}
		}
};
class ConcreteHandler2:public AbstractHandler{
	public:
		ConcreteHandler2(AbstractHandler* handler):AbstractHandler(handler){
		}	
		void handleRequest(Request req){
			if(req.getLevel()==level2){
				cout<<"ConcreteHandler2 "<<req.toString()<<endl;
			}else{
				if(this->successor!=NULL){
					this->successor->handleRequest(req);
				}else{
					cout<<"handle out"<<endl;
				}
			}	
		}
};
class ConcreteHandler3:public AbstractHandler{
	public:
		ConcreteHandler3(AbstractHandler* handler):AbstractHandler(handler){
		}
		void handleRequest(Request req){
			if(req.getLevel()==level3){
				cout<<"ConcreteHandler3 "<<req.toString()<<endl;
			}else{
				if(this->successor!=NULL){
					this->successor->handleRequest(req);
				}else{
					cout<<"handle out"<<endl;
				}
			}	
		}
};
int main(){
	AbstractHandler* handler3=new ConcreteHandler3(NULL);
	AbstractHandler* handler2=new ConcreteHandler2(handler3);
	AbstractHandler* handler1=new ConcreteHandler1(handler2);
	Request req1(level1,"my name is level1");
	Request req2(level2,"my name is level2");
	Request req3(level3,"my name is level3");
	handler1->handleRequest(req1);
	handler1->handleRequest(req2);
	handler1->handleRequest(req3);
	return 0;
} 
