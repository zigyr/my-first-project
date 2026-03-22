/*
班级里共有5位小朋友, 其中存在m对伙伴关系, 每一对关系表示a把b当成朋友
如果a把b当朋友, b把a当朋友, 那么a和b是真朋友
现在请计算，每个人有多少个真朋友

10
1 2
2 1
1 4
1 5
5 1
4 5
5 4
3 4
2 5
4 1
-> [+1+]:3 firend
-> [+2+]:1 firend
-> [+3+]:0 firend
-> [+4+]:2 firend
-> [+5+]:2 firend
*/
#include <iostream>
using namespace std;

const int maxn = 10;
int G[maxn][maxn];

int main (){
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        G[a][b] = 1;
    }
    for (int i = 1; i <= 5; i++){
        int sum = 0;
        for (int j = 1; j <= 5; j++){
            if (G[i][j] && G[j][i]) sum++;
        }
        cout << "[+" << i << "+]" << ":" << sum << " firend" << endl;
    }
}