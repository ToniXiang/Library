#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
	int n,m;
	ll a;
	while(cin>>n){
		for(int sq=1;sq<=n;sq++){
			cout<<"Case "<<sq<<":"<<endl;
			int cost[36]={0};
			for(int i=0;i<36;i++){
				cin>>cost[i];
			}
			cin>>m;
			while(m--){
				cin>>a;
				ll r=1E9;
				vector<int>v;
				for(int i=2;i<=36;i++){
					ll rd=a;
					ll cur_r=0;
					while(rd>0){
						cur_r+=cost[rd%i];
						rd/=i;
					}
					if(r>cur_r){
						r=cur_r;
						v.clear();
					}
					if(r==cur_r)v.push_back(i);
				}
				cout<<"Cheapest base(s) for number "<<a<<": ";
				for(int i=0;i<v.size();i++){
					cout<<v[i]<<(i==v.size()-1?"":" ");
				}
				cout<<endl;
			}
			if(sq!=n)cout<<endl;
		}
	}
	return 0;
}
// 計算各自的價位進行加總，找出最小值