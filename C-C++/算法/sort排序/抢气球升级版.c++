/*
进阶之处在于,1<n,m<10**5
第一行输入n和m，n代表小朋友个数，m代表气球个数
第二行输入n个数，代表第i个小朋友的跳跃高度
第三行输入m个数，代表第i个气球的所在高度
每个小朋友的跳跃高度不同，让跳跃高度低的小朋友先参与
已知每位小朋友都很贪婪，都会把自己能摘到的气球都摘到
*/
#include <iostream>
#include <algorithm>
using namespace std;
struct Child{
    int a;
    int id;
};
Child chi[1005];
int h[1005];
int ans[1005];
int main (){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>chi[i].a;
        chi[i].id=i;
    }
    for(int i=0;i<m;i++){
        cin>>h[i];
    }
    sort(chi,chi+n,[](Child x,Child y){
        return x.a<y.a;
    });
    sort(h,h+m);
    int cur=0;
    int las=0;
    for(int i=0;i<n;i++){
        // while(cur<m&&h[cur]<=chi[i].a){
        //     cur++;
        // }
        // ans[chi[i].id]=cur-las;
        // las=cur;
        while(cur<m&&h[cur]<=chi[i].a){
            ans[chi[i].id]++;
            cur++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<endl;
    }
}