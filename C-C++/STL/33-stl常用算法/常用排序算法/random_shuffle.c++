#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
#include <ctime>

void myPrint(int val){
    cout<<val<<" ";
}

void test01(){
    srand((unsigned int)time(NULL));
    vector<int>v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }

    //利用洗牌算法random_shuffle打乱排序
    random_shuffle(v.begin(),v.end());

    for_each(v.begin(),v.end(),myPrint);
    cout<<endl;
}

int main (){
    test01();
}