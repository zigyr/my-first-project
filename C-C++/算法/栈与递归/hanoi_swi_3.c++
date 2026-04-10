#include <iostream>
using namespace std;
#include <stack>

stack<int> s[3];

int cou = 0;
int act = 0;

void move(int x, int y){
    s[y].push(s[x].top());
    cou++;
    act += s[x].top();
    s[x].pop();
}

void hanoi(int a, int b, int c, int n){
    if (n == 1){
        move(a, c);
        return;
    }
    
    hanoi(a, c, b, n - 1);
    move(a, c);
    hanoi(b, a, c, n - 1);
}

int main (){
    int n;
    cin >> n;
    for (int i = n; i >= 1; i--){
        s[0].push(i);
    }

    hanoi(0, 1, 2, n);

    cout << "count: " << cou << endl;
    cout << "action: " << act << endl;
}