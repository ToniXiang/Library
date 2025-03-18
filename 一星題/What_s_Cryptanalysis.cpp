#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;
typedef pair<char,int> pci;
bool cmp(pci&a,pci&b){//true -> a precede b
	if(a.second!=b.second)return a.second>b.second;
	return a.first<b.first;
}
int main(){
	int n;
	string s;
	while(getline(cin,s)){
		stringstream ss(s);
		ss>>n;
		vector<pci>v;
		while(n--){
			getline(cin,s);
			transform(s.begin(),s.end(),s.begin(),::toupper);
			for(const char&it:s){
				if(it>='A'&&it<='Z'){
					int index=-1;
					for(int j=0;j<v.size();j++){
						if(v[j].first==it){
							index=j;
							break;
						}
					}
					if(index==-1)v.push_back({it,1});
					else v[index].second++;
				}
			}
		}
		sort(v.begin(),v.end(),cmp);
		for(const pci&r:v){
			cout<<r.first<<" "<<r.second<<endl;
		}
	}
	return 0;
}

// 計算每個字母出現的次數，並且按照出現次數由大到小排序，如果次數相同則按照字母順序排序