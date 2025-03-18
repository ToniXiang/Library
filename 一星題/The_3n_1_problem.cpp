#include<iostream>
using namespace std;
typedef long long ll;
ll f(ll n){
	if(n==1)return 1;
	if((n&0x01)==0x01)return f(3*n+1)+1;
	return f(n/2)+1;
}
void swap(int&a,int&b){
	int tmp=a;
	a=b;
	b=tmp;
}
int main(){
	int a,b;
	while(cin>>a>>b){
		ll res=0;
		string s=to_string(a)+" "+to_string(b)+" ";
		if(a>b)swap(a,b);
		for(int i=a;i<=b;i++){
			res=max(res,f(i));
		}
		cout<<s<<res<<endl;
	}
	return 0;
}
// 函數輸入 a~b 計算遞迴次數，取最大值