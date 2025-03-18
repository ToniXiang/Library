#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
bool cmp(pii&a,pii&b){// true -> a precede b
	if(a.second!=b.second)return a.second<b.second;
	else return a.first>b.first;
}
int main(){
	string s;
	bool end=false;
	while(getline(cin,s)){
		if(end)cout<<endl;
		vector<pii>v;
		for(const char&it:s){
			bool fg=true;
			for(int i=0;i<v.size();i++){
				if(it==v[i].first){
					fg=false;
					v[i].second++;
					break;
				}
			}
			if(fg)v.push_back({(int)it,1});
		}
		sort(v.begin(),v.end(),cmp);
		for(const auto&r:v){
			cout<<r.first<<" "<<r.second<<endl;
		}
		end=true;
	}
	return 0;
}