#include <ctime>
#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>
using namespace std;
/*
有五名选手ABCDE，10个评委分别对每一个选手打分，去除最高分和最低分，取平均分
*/

//选手类
class Person{
public:
    Person(string name,int score){
        this->m_Name=name;
        this->m_Score=score;
    }
    string m_Name;//姓名
    int m_Score;//平均分
};

void createPerson(vector<Person>&v){
    string nameSeed="ABCDE";
    for(int i=0;i<5;i++){
        string name="选手";
        name+=nameSeed;
        int score=0;
        Person p(name,score);
        v.push_back(p);
    }
}

void setScore(vector<Person>&v){
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++){
        deque<int>d;
        for(int i=0;i<10;i++){
            int score=rand()%41+60;//60~100
            d.push_back(score);
        }
        sort(d.begin(),d.end());
        d.pop_back();
        d.pop_front();
        int sum=0;
        for(deque<int>::const_iterator dit=d.begin();dit!=d.end();dit++){
            sum+=*(dit);
        }
        int avg=sum/d.size();
        it->m_Score=avg;
    }
}

void showScore(vector<Person>&v){
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++){
        cout<<"name:"<<it->m_Name<<" "<<"avg_score:"<<it->m_Score<<endl;
    }
}

int main (){
    srand((unsigned int)time(NULL));
    //1、创建五名选手
    vector<Person>v;
    createPerson(v);
    //2、给五名选手打分
    setScore(v);
    //3、显示最后得分
    showScore(v);
}