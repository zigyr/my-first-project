#include <stdio.h>

//计算1-n之和
//非递归
int total_sum1(int num){
	int sum=0,T=num;
	do//nb的
	{
		sum+=T;
	}
	while(T--);
	return sum;
}
//递归
int total_sum2(int num){
	if(num==1){
		return 1;
	}else{
		return total_sum2(num-1)+num;
	}
}

//斐波那契数列第n项值
//非递归
int fibonacci1(int n){
	int last1=1,last2=1,result=0;
	for(int i=3;i<=n;i++){
		result=last1+last2;
		last1=last2;
		last2=result;
	}
	return result;
}
//递归
int fibonacci2(int n){
	if(n==1||n==2){
		return 1;
	}else{
		return fibonacci2(n-1)+fibonacci2(n-2);
	}
}


int main (){
	int num=fibonacci2(5);
	printf("%d",num);
}