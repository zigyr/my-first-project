//通过struct声明一个储存学生的姓名和成绩数组
//并按照学生成绩进行排序
//当第一个成绩高时，第一个成绩高的排在前面
//当第一个成绩相同时，第二个成绩高的排在前面
//当前两个成绩相同时，第三个成绩高的排在前面
//当前三个成绩相同时，第四个成绩高的排在前面
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Student{
    string name;
    int score[4];
};
//没有被多条件的过滤吼住，简洁明了
bool cmp(Student x,Student y){
    if(x.score[0]!=y.score[0]){
        return x.score[0]>y.score[0];
    }
    if(x.score[1]!=y.score[1]){
        return x.score[1]>y.score[1];
    }
    if(x.score[2]!=y.score[2]){
        return x.score[2]>y.score[2];
    }
    return x.score[3]>y.score[3];
}
//
int main (){
    Student stu[3];
    for(int i=0;i<3;i++){
        cin>>stu[i].name;
        for(int j=0;j<4;j++){
            cin>>stu[i].score[j];
        }
    }
    sort(stu,stu+3,cmp);
    for(int i=0;i<3;i++){
        cout<<stu[i].name<<":";
        for(int j=0;j<4;j++){
            cout<<stu[i].score[j]<<" ";
        }
        cout<<endl;
    }
}