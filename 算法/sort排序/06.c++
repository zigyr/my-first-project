//第一行输入字符串，R代表红球、G代表绿球、B代表蓝球
//按字典序排列并输出
//按一红二绿三蓝组成一串，求共几串
#include <iostream>
#include <algorithm>
using namespace std;
#include <string>
int main (){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    cout<<s<<endl;
    int b=0,r=0,g=0;
    for(const auto& a:s){
        if(a=='R')r++;
        if(a=='G')g++;
        if(a=='B')b++;
    }
    //一红二绿三蓝
    //对应一红二绿三蓝的算法
    cout<<min(r,min(g/2,b/3));
}