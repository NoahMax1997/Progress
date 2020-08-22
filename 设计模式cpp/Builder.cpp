#include <iostream>
#include <string>
using namespace std;
class StringBuilder{
	private:
		char* value;
		int count;
	public:
	StringBuilder(int capacity){
		count=0;
		value=new char[capacity];	
	}
	~StringBuilder(){
		delete value;
	}
	StringBuilder* append(char c){
		value[count++]=c;
	}
};
int main(){
	
	return 0;
} 
