#include<iostream>
using namespace std;
typedef long long ll;
int main(){
	ll n,m;
	while(cin>>n>>m){
		bool fg=false;
		string s=to_string(n)+" ";
		if(n==1)fg=true;
		while(n>1){
			if(n%m!=0||m==1){
				fg=true;
				break;
			}
			n/=m;
			s+=to_string(n)+" ";
		}
		cout<<(fg?"Boring!":s.substr(0,s.size()-1))<<endl;
	}
	return 0;
}