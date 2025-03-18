#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;
int main(){
	int n,a,rd=0;
	string s;
	while(getline(cin,s)){
		if(s=="")continue;
		stringstream ss(s);
		ss>>n;
		vector<int>v;
		while(n--){
			cin>>a;
			v.push_back(a);
		}
		sort(v.begin(),v.end());
		bool fg=true;
		for(int j=1;j<v.size()-1;j++){
			if(v[j-1]*2!=v[j]){
				fg=false;
				break;
			}
		}
		cout<<"Case #"<<++rd<<": It is"<<(fg?" a ":" not a ")<<"B2-Sequence."<<endl<<endl;
	}
	return 0;
}