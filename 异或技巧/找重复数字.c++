#include <iostream>
using namespace std;
int read(int arr[],int n){
    return;
}
int main (){
    int x=0;
    for(int i=1;i<=100;i++){
        x^=i;
    }
    for(int i=0;i<n;i++){
        x^=arr[i];
    }
    cout<<x;
}