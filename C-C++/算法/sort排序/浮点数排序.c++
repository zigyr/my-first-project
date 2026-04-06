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
    // 用误差容限替代直接的==比较
    // 这是处理浮点数精度问题的标准做法
    if(fabs(da-db)<EPSILON){
        // return 左边 < 右边 --》 升序（把小的放前面，大的放后面）
        //      如果 cmp(a, b)中的 a < b, `return a < b`为true, 则sort默认顺序
        //      如果 cmp(a, b)中的 a > b, `return a < b`为false, 则sort交换顺序
        // reutnr 左边 > 右边 --》 降序
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