// 数字编码转向问题
// 也就是“forward”向前几步 “back”向后几步 “left”向左几步 “right”向右几步
// 最后统计最终位置
// 默认初始是x轴正方向

// 思路：
// 通过dx、dy数组来确认每次一维距离的增减
// 这其中涉及到巧妙的循环变换
#include <iostream>
using namespace std;

// 顺时针编码
// x+1,y x轴正半轴0
// x,y-1 y轴负半轴1
// x-1,y x轴负半轴2
// x,y+1 y轴正半轴3
// 向后(+2)：0->"2"->0, 1->3->1
// 向左(+3)：0->"3"->2->1->0  左逆3
// 向右(+1)：0->"1"->2->3->0  右顺1
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main (){
    int n;
    cin >> n;
    int now_x = 0, now_y = 0;
    int d = 0;
    while (n--){
        string op;
        int x;
        cin >> op >> x;
        if (op[0] == 'b'){
            d = (d + 2) % 4;
        } else if (op[0] == 'l'){
            d = (d + 3) % 4;
        } else if (op[0] == 'r'){
            d = (d + 1) % 4;
        }
        now_x += dx[d] * x;
        now_y += dy[d] * x; 
    }
    cout << now_x << " " << now_y << endl;
}