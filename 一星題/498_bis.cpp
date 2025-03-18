#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
int main(){
	int n,a;
	string s;
	while(cin>>n){
		cin.ignore();
		getline(cin,s);
		stringstream ss(s);
		vector<int>v;
		while(ss>>a){
			v.push_back(a);
		}
		int total=0,m=1;
		for(int i=v.size()-2;i>=0;i--){
			total+=(v.size()-1-i)*m*v[i];
			m*=n;
		}
		cout<<total<<endl;
		//1x-1
		//1	=> 1
		//x^2+x+1
		//2x+1 =>5
	}
	return 0;
}
// 輸入：
// x
// a[0] a[1] a[2] ... a[n]
// 題目：輸出方程式一次微分後帶入 x 的結果
// a[0]*(n - 0)*x^(n−1) + a[1]*(n − 1)*x^(n−2) + . . .+a[n-1]