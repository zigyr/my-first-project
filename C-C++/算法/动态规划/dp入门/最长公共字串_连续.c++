/*
adf123456
awd12345a
-> 5
*/
#include <iostream>
using namespace std;

const int maxn = 1010;
int dp[maxn][maxn];

int main (){
    string a, b;
    cin >> a >> b;
    int lena = a.size();
    int lenb = b.size();
    int ans = INT_MIN;
    for (int i = 1; i <= lena; i++){
        for (int j = 1; j <= lenb; j++){
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = 0;
            ans = max(ans, dp[i][j]);
        }
 
    }
    cout << ans << endl;



}