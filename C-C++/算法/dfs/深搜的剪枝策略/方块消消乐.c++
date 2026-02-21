/*
2
0
1 0
1 0
2 3 2 0
1 2 3 3 0
-> 3 1 1
-> 4 0 -1
*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, st[10][10];
struct T {
    int x, y, pos;  // pos=1:右交换(x和x+1), pos=-1:左交换(x和x-1)
} ans[10];

// 检查是否所有方块都被消除
bool empty() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            if (st[i][j]) return false;
        }
    }
    return true;
}

// 方块下落（重力效果）：每列的非空方块落到最底部
void drop() {
    int temp[10][10];
    memset(temp, 0, sizeof(temp));
    // 遍历每一列，收集非空方块
    for (int x = 0; x < 5; x++) {
        int idx = 0; // 从列的底部开始填充
        for (int y = 0; y < 7; y++) {
            if (st[x][y]) {
                temp[x][idx++] = st[x][y];
            }
        }
    }
    // 把temp的数据复制回st
    memcpy(st, temp, sizeof(st));
}

// 标记并消除所有满足条件的方块，返回是否有消除发生
bool clear() {
    bool to_clear[10][10] = {false}; // 标记需要消除的位置
    bool has_clear = false;

    // 1. 检查横向消除（同一行，至少3个连续相同）
    for (int y = 0; y < 7; y++) { // 遍历每一行（y轴）
        for (int x = 0; x < 5; ) {
            if (st[x][y] == 0) {
                x++;
                continue;
            }
            int end_x = x;
            // 找连续相同的结束位置
            while (end_x + 1 < 5 && st[end_x + 1][y] == st[x][y]) end_x++;
            // 至少3个连续则标记
            if (end_x - x >= 2) {
                has_clear = true;
                for (int i = x; i <= end_x; i++) {
                    to_clear[i][y] = true;
                }
            }
            x = end_x + 1; // 跳过已检查的连续块
        }
    }

    // 2. 检查纵向消除（同一列，至少3个连续相同）
    for (int x = 0; x < 5; x++) { // 遍历每一列（x轴）
        for (int y = 0; y < 7; ) {
            if (st[x][y] == 0) {
                y++;
                continue;
            }
            int end_y = y;
            // 找连续相同的结束位置
            while (end_y + 1 < 7 && st[x][end_y + 1] == st[x][y]) end_y++;
            // 至少3个连续则标记
            if (end_y - y >= 2) {
                has_clear = true;
                for (int i = y; i <= end_y; i++) {
                    to_clear[x][i] = true;
                }
            }
            y = end_y + 1; // 跳过已检查的连续块
        }
    }

    // 3. 执行消除（把标记的位置置0）
    if (has_clear) {
        for (int x = 0; x < 5; x++) {
            for (int y = 0; y < 7; y++) {
                if (to_clear[x][y]) st[x][y] = 0;
            }
        }
    }

    return has_clear;
}

// DFS搜索：step表示当前是第几步交换
void dfs(int step) {
    // 达到指定步数，检查是否清空
    if (step == n + 1) {
        if (empty()) {
            for (int i = 1; i <= n; i++) {
                // 样例输出是从1开始计数，所以x/y要+1
                printf("%d %d %d\n", ans[i].x, ans[i].y, ans[i].pos);
            }
            exit(0); // 找到解直接退出程序
        }
        return;
    }

    // 临时剪枝（可选）：注释掉也能跑通样例，保留则加快速度
    int sum[12] = {0};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            sum[st[i][j]]++;
        }
    }
    for (int i = 1; i <= 10; i++) {
        if (sum[i] > 0 && sum[i] < 3) {
            return;
        }
    }

    // 尝试所有可能的交换操作
    int backup[10][10]; // 备份当前状态
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 7; y++) {
            if (!st[x][y]) continue; // 空位置跳过

            // 操作1：向右交换（x和x+1），pos=1
            if (x != 4) {
                memcpy(backup, st, sizeof(backup)); // 备份
                swap(st[x][y], st[x+1][y]);         // 交换
                drop();                             // 下落
                while (clear()) drop();             // 消除+下落循环
                ans[step] = {x, y, 1};              // 记录操作
                dfs(step + 1);                      // 递归下一步
                memcpy(st, backup, sizeof(st));     // 恢复状态
            }

            // 操作2：向左交换（x和x-1），pos=-1（移除st[x-1][y]==0的限制）
            if (x != 0) {
                memcpy(backup, st, sizeof(backup)); // 备份
                swap(st[x][y], st[x-1][y]);         // 交换
                drop();                             // 下落
                while (clear()) drop();             // 消除+下落循环
                ans[step] = {x, y, -1};             // 记录操作
                dfs(step + 1);                      // 递归下一步
                memcpy(st, backup, sizeof(st));     // 恢复状态
            }
        }
    }
}

int main() {
    memset(st, 0, sizeof(st)); // 初始化数组为0
    scanf("%d", &n);

    // 读取输入：5列，每列以0结束
    for (int i = 0; i < 5; i++) {
        int val, j = 0;
        while (scanf("%d", &val) == 1 && val != 0) {
            st[i][j++] = val;
        }
    }

    dfs(1);          // 从第1步开始搜索
    printf("-1\n");  // 没有找到解
    return 0;
}