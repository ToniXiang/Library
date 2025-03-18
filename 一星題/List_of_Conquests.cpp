#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;
typedef pair<string,int> psi;
bool cmp(psi&a,psi&b){
	return a.first[0]<b.first[0];
}
int main(){
	int n;
	string s;
	while(cin>>n){
		cin.ignore();
		vector<psi>v;
		while(n--){
			getline(cin,s);
			stringstream ss(s);
			ss>>s;
			bool fg=true;
			for(int i=0;i<v.size();i++){
				if(v[i].first==s){
					v[i].second++;
					fg=false;
					break;
				}
			}
			if(fg)v.push_back({s,1});
		}
		sort(v.begin(),v.end(),cmp);
		for(const psi&it:v){
			cout<<it.first<<" "<<it.second<<endl;
		}
	}
	return 0;
}
//輸入字串以空格分割，只處理第一個單詞
//升序(map本身自動排序)將每個單詞及其頻率輸出