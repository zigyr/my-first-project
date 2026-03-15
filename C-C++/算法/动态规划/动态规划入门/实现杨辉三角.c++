/*
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
*/
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 55;

ll f[N][N];

void init(){
    for (int i = 1; i < N; i++){
        for (int j = 1; j <= i; j++){
            if (j == 1){
                f[i][j] = 1;
            } else{
                f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
            }
        }
    }
}


int main (){
    init();
    int n, m;
    cin >> n >> m;
    cout << f[n][m] << endl;
}