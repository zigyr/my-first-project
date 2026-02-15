/*
输入一个二维数组的字符串
S代表起点，T代表终点，.代表能走的路，*代表障碍物
输出一条从S到T的路径，也就是将路径上的.变成m，从新打印二维数组
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