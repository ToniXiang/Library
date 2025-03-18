#include<iostream>
#include<vector>
#include<iomanip>
#include<sstream>
using namespace std;
typedef long long ll;
vector<pair<ll,string>>v{{(ll)1E2,"lakh"},{(ll)1E2,"hajar"},{(ll)1E1,"shata"},{(ll)1E2,""}};
int main(){
	ll n;
	string s;
	int rd=0;
	while(getline(cin,s)){
		if(s=="")break;
		stringstream ss(s);
		ss>>n;
		string r="";
		for(int i=v.size()-1;i>=0;i--){
			if(n==0)break;
			ll q=n%v[i].first;
			n/=v[i].first;
			if(q!=0)r=" "+to_string(q)+(i==v.size()-1?"":" ")+v[i].second+r;
		}
		if(n!=0)r=" kuti"+r;
		for(int i=v.size()-1;i>=0;i--){
			if(n==0)break;
			ll q=n%v[i].first;
			n/=v[i].first;
			if(q!=0)r=" "+to_string(q)+(i==v.size()-1?"":" ")+v[i].second+r;
		}
		if(n!=0)r=" "+to_string(n)+" kuti"+r;
		if(r=="")r=" 0";
		cout<<setfill(' ')<<setw(4)<<++rd<<"."<<r<<endl;
	}
	return 0;
}

// 1E2 shata
// 1E3 hajar
// 1E5 lakh
// 1E7 kuti
// 1E9 shata (kuti)
// 1E10 hajar (kuti)
// 1E12 lakh (kuti)
// 1E14 kuti (kuti)
// 1. 9 kuti 99 lakh 99 hajar 9 shata 99 kuti 99 lakh 99 hajar 9 shata 99