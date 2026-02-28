#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

vector<int> getDivisors(int n){
    vector<int> res;
    for (int i = 1; i * i <= n; i++){
        if (n % i == 0){
            res.push_back(i);
        }
        if (i != n / i){
            res.push_back(n / i);
        }
    }
    return res;
}

int main (){
    int n;
    cin >> n;
    vector<int> res = getDivisors(n);
    sort(res.begin(), res.end());
    for (const auto& a:res){
        cout << a << " ";
    }
}