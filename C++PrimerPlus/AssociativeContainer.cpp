#include <set>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <queue>
using namespace std;
void SetTest(){
    string a[5]={"b","c","a","e","f"};
    vector<string> b={"b","c","a","e","f"};
    set<string,greater<string> > str_set1(a,a+5);
    set<string> str_set2(b.begin(),b.end());
    ostream_iterator<string,char> oiter(cout," ");
    copy(str_set1.begin(),str_set1.end(),oiter);
    cout<<endl;
    copy(str_set2.begin(),str_set2.end(),oiter);
    cout<<endl;
    cout<<*str_set1.lower_bound("d")<<endl;//set 里面排后面的就大
    cout<<*str_set1.upper_bound("b")<<endl;
    cout<<*str_set2.lower_bound("d")<<endl;//>=的最小迭代器
    cout<<*str_set2.upper_bound("b")<<endl;//>的最小迭代器
}
void PriorityQueue(){
    priority_queue<int> queue1;
}
int main (){
    SetTest();
    system("pause");
    return 0;
}