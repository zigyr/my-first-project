//选择排序：时间复杂度-O(n**2)
#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[],int len){
	for(int i=0;i<len;i++){
		int min=i;
		for(int j=i;j<len;j++){
			if(arr[j]<arr[min])min=j;
		}
		// cout<<arr[i]<<" "<<arr[min]<<endl;
		swap(arr[i],arr[min]);
	}
}

int main (){
	int arr[] = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
	selection_sort(arr,11);
	for(auto a:arr){
		cout<<a<<" "; 
	}
}