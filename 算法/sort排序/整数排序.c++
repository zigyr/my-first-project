//将N个正整数按照除以3的余数从小到大排序，
//即将余0的数排在最前面，余2的数放在最后，
//如果余数相等，则按照正整数的值从小到大排序
#include <iostream>
#include <algorithm>
using namespace std;
int num[105];
//对题目的理解，通过sort进行解决，这一步惊艳到我了
bool cmp(int x,int y){
    if(x%3!=y%3){
        return x%3<y%3;
    }else{
        return x<y;
    }
}
//
int main (){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num[i];
    }
    sort(num,num+N,cmp);
    for(int i=0;i<N;i++){
        cout<<num[i]<<" ";
    }
    cout<<endl;
}