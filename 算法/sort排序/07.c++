//输入一串数字
//计算每个数字的各个位数上的数字之和，谁小谁在前
//如果计算结果相同，则原数谁小谁在前
#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>

int main (){
    int N;
    cin>>N;
    vector<int>v;
    int tmp;
    for(int i=0;i<N;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end(),[](int x,int y){
        int xx=x,yy=y;
        int sumx=0,sumy=0;
        while(x){
            sumx+=x%10;
            x/=10;
        }
        while(y){
            sumy+=y%10;
            y/=10;
        }
        if(sumx==sumy){
            return xx<yy;
        }else{
            return sumx<sumy;
        }
    });
    for(const auto& a:v){
        cout<<a<<" ";
    }
}