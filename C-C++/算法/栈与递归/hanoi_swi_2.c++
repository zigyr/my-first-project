#include <iostream>
using namespace std;

// cou(n) = cou(n-1)*2 + 1
int cou(int n){
    if (n == 1)
        return 1;
    return cou(n - 1) * 2 + 1;
}

// act(n) = act(n-1)*2 + n
int act(int n){
    if (n == 1)
        return 1;
    return act(n - 1) * 2 + n;
}

int main (){
    int n;
    cin >> n;
    cout << "count: " << cou(n) << endl;
    cout << "action: " << act(n) << endl;
}