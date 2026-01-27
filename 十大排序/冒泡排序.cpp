//冒泡排序：时间复杂度-O(n**2)
#include <bits/stdc++.h>
using namespace std;
void bubble_sort(int arr[],int len){
	for(int i=0;i<len-1;i++){
		for(int j=0;j<len-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
	}
}
int main (){
	int arr[] = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
	bubble_sort(arr,11);
	for(int i=0;i<11;i++){
		cout<<arr[i]<<" ";
	}
}