//将数组中第l1到第r1个数字元素从小到大排序
//再将数组中第l2到第r2个数字元素从大到小排序
#include <iostream>
#include <algorithm>
using namespace std;
int num[105];
int main (){
    int N,l1,r1,l2,r2;
    cin>>N>>l1>>r1>>l2>>r2;
    for(int i=0;i<N;i++){
        cin>>num[i];
    }
    // 想一想普通的`sort(a, a + n)`, 不难推的
    sort(num + l1 - 1, num + r1);
    sort(num + l2 - 1, num + r2, greater<int>());
    for(int i=0;i<N;i++){
        if(i>0)cout<<" ";
        cout<<num[i];
    }
    cout<<endl;
}