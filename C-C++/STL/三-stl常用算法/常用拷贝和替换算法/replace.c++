#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class myPrint{
public:
    void operator()(int val){
        cout<<val<<" ";
    }
};
// void myPrint(int val){
//     cout<<val<<" ";
// }

void test01(){
    vector<int>v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    for_each(v.begin(),v.end(),myPrint());
    // for_each(v.begin(),v.end(),myPrint);
    cout<<endl;

    //替换后：
    replace(v.begin(),v.end(),9,900);
    for_each(v.begin(),v.end(),myPrint());
    // for_each(v.begin(),v.end(),myPrint);
    cout<<endl;

    
}

int main (){
    test01();
}