#include<iostream>
using namespace std;
int f(char ch){
	if(ch>='a'&&ch<='z')return ch-'a'+36;
	if(ch>='A'&&ch<='Z')return ch-'A'+10;
	return ch-'0';
}
int main(){
	string s;
	while(getline(cin,s)){
		int sum=0;
		int t=2;
		string r="such number is impossible!";
		for(int i=0;i<s.size();i++){
			if(s[i]!='+'&&s[i]!='-'&&s[i]!=' '){
				sum+=f(s[i]);
				t=max(t,f(s[i]));
			}
		}
		for(int i=t;i<63;i++){
			if(sum%i==0){
				r=to_string(i+1);
				break;
			}
		}
		cout<<(sum<=1?"2":r)<<endl;
	}
	return 0;
}

// 題目：給定一個 res 進制 s 保證可以被 (res-1) 整除，求最小的 res
// 【abc】是 (res - 1) 的倍數，則【a + b + c】也是(res -1)的倍數