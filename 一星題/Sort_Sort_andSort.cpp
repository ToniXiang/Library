#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct data{
	int val;
	int two;
	int mod;
};
bool cmp(data&a,data&b){//如果返回 true，表示 a 應該排在 b 前面
	if(a.mod!=b.mod)return a.mod<b.mod;//not same MOD->larger precede small
	if(a.two!=b.two)return a.two>b.two;//not same O&E->odd precede even
	if(a.two==1)return a.val>b.val;//same odd->larger precede small
	return a.val<b.val;//same even->small precede even
}
int main(){
	int n,m,a;
	while(cin>>n>>m){
		cout<<n<<" "<<m<<endl;
		if(n==0&&m==0)break;
		vector<data>v;
		while(n--){
			cin>>a;
			v.push_back({a,(a&0x01),a%m});
		}
		sort(v.begin(),v.end(),cmp);
		for(data& i:v){
			cout<<i.val<<endl;
		}
	}
	return 0;
}