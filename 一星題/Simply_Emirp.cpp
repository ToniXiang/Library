#include<iostream>
using namespace std;
typedef long long ll;
bool isprime(ll&n){
	if(n<=1)return false;
	if(n<=3)return true;
	if(n%2==0||n%3==0)return false;
	for(int i=5;i*i<=n;i+=6){
		if(n%i==0||n%(i+2)==0)return false;
	}
	return true;
}
string check(ll& a,ll& b){
	bool A=isprime(a);
	bool B=isprime(b);
	if(a==b&&A)return "prime";
	if(A&&B)return "emirp";
	if(!A&&B)return "prime";
	return "not prime";
}
int main(){
	string s;
	while(cin>>s){
		int p10=1;
		ll a=0,b=0;
		for(int i=0;i<s.size();i++){
			a+=p10*(s[i]-'0');
			b+=p10*(s[s.size()-1-i]-'0');
			p10*=10;
		}
		cout<<b<<" is "<<check(a,b)<<"."<<endl;
	}
	return 0;
}
// 題目：輸入一個數字，判斷是否為 Prime、Emirp 或者都不是
// 17 is Emirp because 17 as well as 71 are Prime.