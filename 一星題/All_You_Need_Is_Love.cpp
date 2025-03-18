#include<iostream>
using namespace std;
int cnv10(string s){
	int r=0,m=1;
	for(int i=s.size()-1;i>=0;i--){
		r+=m*(s[i]-'0');
		m<<=1;
	}
	return r;
}
int gcd(int a,int b){
	if(a==1)return b;
	return (a%b==0?b:gcd(b,a%b));
}
int main(){
	int n;
	string a,b;
	while(cin>>n){
		for(int i=1;i<=n;i++){
			cin>>a;
			cin>>b;
			int x=cnv10(a),y=cnv10(b);
			cout<<"Pair #"<<i<<": "<<(gcd(x,y)!=1?"All you need is love!":"Love is not all you need!")<<endl;
		}
	}
	return 0;
}
// 輸入：
// n
// a1
// b2
// ...
// an
// bn
// 題目：輸入 n 組二進位數字，判斷兩數 a 、 b 的最大公因數是否大於 1