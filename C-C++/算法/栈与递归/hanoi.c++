/*
汉诺塔问题：
    有 3 根柱子（A、B、C）
    有 n 个从小到大的盘子，一开始全部放在 A 柱
    要求：把所有盘子移到 C 柱
    限制：大盘不能放在小盘上面
*/
#include <iostream>
using namespace std;
#include <stack>

/*
    s[0] A柱
    s[1] B柱
    s[2] C柱
*/
stack<int> s[3];

/*移动 x柱 最上边的一个盘子到 y柱*/
void move(int x, int y){
    s[y].push(s[x].top());
    s[x].pop();
    cout << x << "-->" << y << endl;
}

/*
想把n个盘子 从A移动到C：
    先把上面的n-1个盘子从A经过C移动到B
    再把A柱最底层(即最大的)从A移动到C
    最后把n-1个盘子从B经过A移动到C
*/
void hanoi(int a, int b, int c, int n){
    // 如果只有一个盘子
    // 则直接从A移动到C
    if (n == 1){
        move(a, c);
        return;
    }

    // 1、先把上面的n-1个盘子从A经过C移动到B
    hanoi(a, c, b, n - 1);
    // 2、再把A柱最底层(即最大的)从A移动到C
    move(a, c);
    // 3、最后把n-1个盘子从B经过A移动到C
    hanoi(b, a, c, n - 1);
}


int main (){
    int n;
    cin >> n;
    // 汉诺塔问题初始化
    for (int i = n; i >= 1; i--){
        s[0].push(i);
    }

    // 汉诺塔转换
    hanoi(0, 1, 2, n);

    // 校验C柱
    while(!s[2].empty()){
        cout << s[2].top() << " ";
        s[2].pop();
    }
}