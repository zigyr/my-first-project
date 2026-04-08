/*
读入n个同学的信息 
每个信息包含一个班级的编号和名字
把相应班级中的相应名字数量加1
*/
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main (){
    int n;
    cin >> n;
    map<int, map<string, int>>info;
    for (int i = 0; i < n; i++){
        int id;
        string name;
        cin >> id >> name;
        // 二维map还可以这样玩
        info[id][name]++;
    }
    // 标准的二维map的遍历, 值得学习
    for (map<int, map<string, int>>::iterator it = info.begin(); it != info.end(); it++){
        for (map<string, int>::iterator dit = (*it).second.begin(); dit != (*it).second.end(); dit++){
            cout << "There are " << dit->second << " people named " << dit->first << " in class " << it->first << endl;
        }
    }
}