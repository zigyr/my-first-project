#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

vector<int> getDivisors(int n){
    vector<int> res;

    for (int i = 1; i * i <= n; i++){
        if (!(n % i)) res.push_back(i);
        if (!(i == n / i)) res.push_back(n / i);
    }

    sort(res.begin(), res.end());

    return res;
}

int main (){
    int n;
    cin >> n;
    vector<int> res = getDivisors(n);
    for (const auto& a:res){
        cout << a << " ";
    }
}