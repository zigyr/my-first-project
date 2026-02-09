/*
再10X9的棋盘上，从S出发，看是否能到达T
.为通路
#为障碍
S为起点，T为终点
*/
#include <iostream>
using namespace std;
string s[10];
int vis[10][10];
int dir[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
bool f;
bool in(int x,int y){
    return 0<=x && x<10 && 0<=y && y<9;
}
void dfs(int x,int y){
    if(f) return;
    vis[x][y]=1;
    if(s[x][y]=='T'){
        f=true;
        return;
    }
    for(int i=0;i<8;i++){
        int tx=x+dir[i][0];
        int ty=y+dir[i][1];
        if(in(tx,ty) && !vis[tx][ty] && s[tx][ty]!='#'){
            dfs(tx,ty);
        }
    }
    //不用回溯
    //只能判断 “可达性”，无法找所有路径 / 最短路径
    // vis[x][y]=0;
}
int main (){
    for(int i=0;i<10;i++){
        cin>>s[i];
    }
    int x,y;
    for(int i=0;i<10;i++){
        for(int j=0;j<9;j++){
            if(s[i][j]=='S'){
                x=i;
                y=j;
            }
        }
    }
    dfs(x,y);
    if(f){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}