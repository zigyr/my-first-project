//N个正浮点数
//按这些浮点数距离它最近的整数的差从小到大排序
//如果差相等，按照浮点数的值从小到大排序
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const double EPSILON=1e-6;
double num[105];
bool cmp(double a,double b){
    double da=fabs(a-round(a));
    double db=fabs(b-round(b));
    if(fabs(da-db)<EPSILON){
        return a<b;
    }
    return da<db;
}
int main (){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num[i];
    }
    sort(num,num+N,cmp);
    for(int i=0;i<N;i++){
        if(i>0)cout<<" ";
        printf("%lf",num[i]);//默认六位小数位
    }
}