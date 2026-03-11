/*
3
1 -2 3
-> 3
*/
#include <iostream>
using namespace std;

const int maxn = 1010;
int a[maxn];
int ans = INT_MIN;

int main (){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        ans = max(ans, a[i]);
    }
    if (ans <= 0){
        cout << ans << endl;
    } else{
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += a[i];
            if (sum < 0) sum = 0;
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
}