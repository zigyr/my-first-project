#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

string add(string a, string b){
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int len = max(a.size(), b.size());
    
    string res;
    int carry = 0;

    for (int i = 0; i < len; i++){
        int digit_a = (i < a.size()) ? (a[i] - '0') : 0;
        int digit_b = (i < b.size()) ? (b[i] - '0') : 0;
        int total = digit_a + digit_b + carry;
        res.push_back((total % 10) + '0');
        carry = total / 10;
    }
    if (carry){
        res.push_back(carry + '0');
    }
    reverse(res.begin(), res.end());
    return res;
}

int main (){
    string a = "123456789012345678901234567890";
    string b = "987654321098765432109876543210";
    cout << add(a, b) << endl;
}
/*
def add(a, b):
    if (len(a) < len(b)):
        a, b = b, a
    a = a[::-1];
    b = b[::-1];
    res = [];
    carry = 0;
    for i in range(len(a)):
        digit_a = int(a[i])
        digit_b = int(b[i]) if i < len(b) else 0
        total = digit_a + digit_b + carry
        res.append(str(total % 10));
        carry = total / 10
    if carry:
        res.append(str(carry))
    return ''.join(reversed(res))
*/