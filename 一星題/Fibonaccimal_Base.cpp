#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	vector<ll>v{1};
	int cur=2;
	while(cur<1E8){
		v.push_back(cur);
		cur=cur+v[v.size()-2];
	}
	int n;
	ll a;
	while(cin>>n){
		while(n--){
			cin>>a;
			ll rd=a;
			string s="";
			int index=distance(v.begin(),upper_bound(v.begin(),v.end(),rd));
			for(int i=index;i>=0;i--){
				if(rd>=v[i]){
					s+="1";
					rd-=v[i];
				}
				else s+="0";
			}
			cout<<a<<" = "<<s.substr(1)<<" (fib)"<<endl;
		}
	}
	return 0;
}