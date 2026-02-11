/*  
输入只有字符'('和')'组成的字符串
一个'('只能匹配唯一的')',第一个'('匹配最后一个')'
如果完全匹配，输出yes，
接下来若干行每行输出两个整数，
表示所有匹配的括号的位置；
如果不完全匹配，输出no。
*/
#include <cstdio>
#include <stack>
#include <cstring>

char str[2000];
std::stack<int> s;
int ans[2000];

int main (){
    scanf("%s",str);
    bool f=true;
    for(int i=0;i<strlen(str);i++){
        if(str[i]=='('){
            s.push(i+1);
        }else{
            if(!s.empty()){
                ans[i+1]=s.top();
                s.pop();
            }else{
                f=false;
                break;
            }
        }
    }
    if(!s.empty()){
        f=false;
    }
    if(!f){
        printf("no\n");
    }else{
        printf("yes\n");
        //注意这里的范围是<=strlen(str)
        for(int i=1;i<=strlen(str);i++){
            //去扫一遍ans，如果不为0，就是一个result
            if(ans[i]){
                printf("%d %d\n",ans[i],i);
            }
        }
    }
}