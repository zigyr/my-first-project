#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main (){
    int n;
    cin >> n;

    vector<int> res;
    // 注意是i是从1开始的
    for (int i = 1; i * i <= n; i++){
        if (!(n % i)) res.push_back(i);
        if (!(i == n / i)) res.push_back(n / i);
    }
    sort(res.begin(), res.end());

    for (const auto& a:res){
        cout << a << " ";
    }
}