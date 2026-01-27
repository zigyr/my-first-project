#include <iostream>
#include <cctype>//isdigit()
#include <stack>
#include <string>
using namespace std;
#include <map>

typedef char ElemType;

void in_symbol(map<char,int>&m){
    m.insert(make_pair('(',0));
    m.insert(make_pair(')',19));
    m.insert(make_pair('+',12));
    m.insert(make_pair('-',12));
    m.insert(make_pair('*',13));
    m.insert(make_pair('/',13));
    m.insert(make_pair('%',13));
    m.insert(make_pair('\0',0));
}
void out_symbol(map<char,int>&m){
    m.insert(make_pair('(',20));
    m.insert(make_pair(')',19));
    m.insert(make_pair('+',12));
    m.insert(make_pair('-',12));
    m.insert(make_pair('*',13));
    m.insert(make_pair('/',13));
    m.insert(make_pair('%',13));
    m.insert(make_pair('\0',0));
}

string eval(stack<ElemType>&s,string expr){
    string res;
    map<char,int>in_map;in_symbol(in_map);
    map<char,int>out_map;out_symbol(out_map);
    int index=0;
    s.push('\0');
    char tmp=expr[index++];
    while(tmp!='\0'){
        if(isdigit(tmp)){
            res+=tmp;
        }else if(tmp==')'){
            while(s.top()!='('){
                res+=s.top();
                s.pop();
            }
            s.pop();
        }else{
            while(((in_map.find(s.top())->second))>=((out_map.find(tmp))->second)){
                res+=s.top();
                s.pop();
            }
            s.push(tmp);
        }
        tmp=expr[index++];
    }
    while(!s.empty()){
        res+=s.top();
        s.pop();
    }
    return res;
}

int main (){
    stack<ElemType>s;
    string expr="8/2+2-5*6";//82/2+56*-
    //string expr="1/(3-4)*2";//134-/2*
    cout<<eval(s,expr);
}