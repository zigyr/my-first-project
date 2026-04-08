/*
第一行输入两个数n、m  
n代表本市的人数 接下来n行输入每个人的身高、体重、年龄
m代表罪犯的人数 接下来m行输入每个人的身高、体重、年龄
输出m行
每行yes or no 代表罪犯是否是本市的
3 2
166 50 30
178 60 23
132 40 15
167 50 30
178 60 23
-> no
-> yes
*/
/*
灵活应用了
set的自定义数据类型插入、仿函数、查找之类的内容
*/
#include <iostream>
using namespace std;
#include <set>
class People{
public:
    int h, w, a;
    People(int h_, int w_, int a_) : h(h_), w(w_), a(a_) {}
    bool operator <(const People& p)const{
        return h < p.h;  // 升序
    }
};

int main (){
    int n, m;
    cin >> n >> m;
    set<People> s;
    int h_tmp, w_tmp, a_tmp;
    for(int i = 0; i < n; i++){
        cin >> h_tmp >> w_tmp >> a_tmp;
        People p_tmp(h_tmp, w_tmp, a_tmp); //带参构造函数
        s.insert(p_tmp);
    }
    for (int i = 0; i < m; i++){
        cin >> h_tmp >> w_tmp >> a_tmp;
        People p_tmp(h_tmp, w_tmp, a_tmp);
        set<People>::iterator pos = s.find(p_tmp);
        if (pos != s.end()){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
}