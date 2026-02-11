//N名学生，4课成绩，取总分前三名
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct Student{
    string name;
    int score[4];
};
bool cmp(Student x,Student y){
    //这里很巧妙
    int sumx=x.score[0]+x.score[1]+x.score[2]+x.score[3];
    int sumy=y.score[0]+y.score[1]+y.score[2]+y.score[3];
    return sumx>sumy;
}
Student stu[50];
int main (){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>stu[i].name;
        for(int j=0;j<4;j++){
            cin>>stu[i].score[j];
        }
    }
    sort(stu,stu+N,cmp);
    for(int i=0;i<3;i++){
        cout<<stu[i].name<<endl;
    }
}