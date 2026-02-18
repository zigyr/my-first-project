/*
3 4
S**.
....
***T
-> 5
*/
#include <iostream>
#include <string>
#include <climits>
using namespace std;
int n,m;
bool vis[105][105];
string maze[105];
bool in(int x,int y){
    return 0<=x && x<n && 0<=y && y<m;
}
//向上 向左 向下 向右
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
int ans=INT_MAX;
void dfs(int x,int y,int step){
    if(maze[x][y]=='T'){
        if(step<ans){
            ans=step;
        }
        return;
    }
    vis[x][y]=1;
    for(int i=0;i<4;i++){
        int tx=x+dir[i][0];
        int ty=y+dir[i][1];
        // 注意这里
        // 先判断坐标合法，再访问数组检验是否可通
        if(in(tx,ty) && !vis[tx][ty] && maze[tx][ty]!='*'){
            dfs(tx,ty,step+1);
        }
    }
    //回溯
    vis[x][y]=0;
}
int main (){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>maze[i];
    }
    int x,y;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maze[i][j]=='S'){
                x=i,y=j;
            }
        }
    }
    dfs(x,y,0);
    cout<<ans<<endl;
}