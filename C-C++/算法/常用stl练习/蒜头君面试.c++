/*

*/
#include <iostream>
using namespace std;
// #include <algorithm>
#include <climits>
// int arr[10000];
#include <map>
map<int, int>mp;
int main (){
    int n;
    cin >> n;
    // for (int i = 0; i < n; i++){
    //     cin >> arr[i];
    // }
    // sort (arr, arr + n);
    // int cou;
    // int res_cou = INT_MIN;
    // int res_val;
    // int tmp;
    // for (int i = 0; i < n;){
    //     cou = 1;
    //     tmp = arr[i];
    //     // 这里很重要, 解引
    //     while (*(arr + i) == *(arr + i + cou)){
    //         cou++;
    //     }      
    //     if (cou >= res_cou){
    //         res_cou = cou;
    //         res_val = tmp;
    //     }  
    //     i += cou;
    // }
    int tmp;
    for (int i = 0; i < n; i++){
        cin >> tmp;
        mp[tmp]++;
    }
    int res_val, res_cou = INT_MIN;
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++){
        if (it->second >= res_cou){
            res_cou = it->second;
            res_val = it->first;
        }
    }
    cout << res_val << " " << res_cou;
}