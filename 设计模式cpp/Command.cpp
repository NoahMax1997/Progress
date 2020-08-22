#include <iostream>
using namespace std;
//class AbstractHandle;
class Light{
	public:
		void on(){
			cout<<"litht on"<<endl;
		}
		void off(){
			cout<<"litht off"<<endl;
		}
};
class Command{
	public:
		virtual void  excute()=0;
};
class LightOnCommand:public Command{
	private:Light* light;
	public:
		LightOnCommand(){
		}
		LightOnCommand(Light* light):light(light){
		}
		void  excute(){
			light->on();
		} 
};
class LightOffCommand:public Command{
	private:Light* light;
	public:
		LightOffCommand(){
		}
		LightOffCommand(Light* light):light(light){
		}
		void  excute(){
			light->off();
		}
};
class Invoke{
	private:
		LightOnCommand* on_command;
		LightOffCommand* off_command;
		int size,on_index,off_index;
	public:
		Invoke(int size):size(size){
			on_command=new LightOnCommand[size];
			off_command=new LightOffCommand[size];
		}
		void pushOnDown(int index){
			on_command[index].excute();
		}
		void pushOffDown(int index){
			off_command[index].excute();
		}
		void setOnCommand(int index,LightOnCommand& command){
//			cout<<"setOnCommand"<<endl;
			on_command[index]=command;
//			cout<<"setOnCommand end"<<endl;
		}
		void setOffCommand(int index,LightOffCommand& command){
//			cout<<"setOffCommand"<<endl;
			off_command[index]=command;
//			cout<<"setOffCommand end"<<endl;
		}
		int getSize(){
			return size;
		}
		void setSize(int size){
			this->size=size;
		}
		int getOnIndex(){
			return on_index;
		}
		void setOnIndex(int index){
			on_index=index;
		}
		int getOffIndex(){
			return off_index;
		}
		void setOffIndex(int index){
			off_index=index;
		}
};
int main(){
	Invoke in(10);
	Light* light=new Light();
	
	LightOnCommand c1(light);
	LightOffCommand c2(light);
//	Command c=c1;
	in.setOnCommand(0,c1);
	in.setOffCommand(0,c2);
	in.pushOnDown(0);
	in.pushOffDown(0);
	return 0;
} 
