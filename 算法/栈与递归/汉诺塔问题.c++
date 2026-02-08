#include <iostream>
#include <stack>
using namespace std;
stack<int>s[3];
void move(int x,int y){
    s[y].push(s[x].top());
    s[x].pop();
    printf("%d--->%d\n",x,y);
}
void hanoi(int A,int B,int C,int n){
    if(n==1){
        move(A,C);
        return;
    }
    hanoi(A,C,B,n-1);
    move(A,C);
    hanoi(B,A,C,n-1);
}
int main (){
    int n;
    cin>>n;
    //起始s[0]即A柱
    for(int i=n;i>=1;i--){
        s[0].push(i);
    }
    //汉诺塔式转变
    hanoi(0,1,2,n);
    //检验s[2]即C柱
    while(!s[2].empty()){
        cout<<s[2].top()<<" ";
        s[2].pop();
    }
}