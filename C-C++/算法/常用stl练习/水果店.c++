/*
5
apple shandong 3
pineapple guangdong 1
sugarcane guangdong 1
pineapple guangdong 3
pineapple guangdong 1
-> guangdong
->    |----pineapple(5)
->    |----sugarcane(1)
-> shandong
->    |----apple(3)
*/
#include <iostream>
using namespace std;
#include <map>
#include <string>
map<string, map<string, int>> mp;
int main (){
    int n;
    cin >> n;
    int op;
    string fru, add;
    for (int i = 0; i < n; i++){
        cin >> fru >> add >> op;
        // 同二维map
        mp[add][fru] += op;
    }
    for (map<string, map<string, int>>::iterator it = mp.begin(); it != mp.end(); it++){
        cout << it->first << endl;
        for (map<string, int>::iterator dit = it->second.begin(); dit != it->second.end(); dit++){
            cout << "   |----" << dit->first << "(" << dit->second << ")" << endl;
        }
    }
}