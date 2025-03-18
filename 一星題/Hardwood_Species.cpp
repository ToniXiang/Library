#include<iostream>
#include<map>
#include<iomanip>
using namespace std;
int main(){
	string s;
	int n;
	while(cin>>n){
		cin.ignore();
		getline(cin,s);
		bool end=false;
		while(n--){
			if(end)cout<<endl;
			map<string,int>mp;
			double len=0;
			while(getline(cin,s)){
				if(s=="")break;
				mp[s]++;
				len++;
			}
			for(const auto&it:mp){
			cout<<fixed<<setprecision(4)<<it.first<<" "<<((double)it.second*100)/len<<endl;
			}
			end=true;
		}
	}
	return 0;
}
//7/30=x/100 => x=7*100/30=700/30=>23.333...