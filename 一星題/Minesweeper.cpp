#include<iostream>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
int main(){
	int n,m;
	char ch;
	int rd=0;
	bool end=false;
	while(cin>>n>>m){
		if(n==0&&m==0)break;
		if(end)cout<<endl;
		cout<<"Field #"<<++rd<<":"<<endl;
		int mp[n][m]={0};
		vector<pii>pt;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				mp[i][j]=0;
				cin>>ch;
				if(ch=='*'){
					pt.push_back({i,j});
					mp[i][j]=-1;
				}
			}
		}
		for(const pii&it:pt){
			for(int a=it.first-1;a<=it.first+1;a++){
				for(int b=it.second-1;b<=it.second+1;b++){
					if(a<0||b<0||a>=n||b>=m||mp[a][b]==-1)continue;
					mp[a][b]+=1;
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){ // tip ?: must use same type like x = (bool) ? string : string
				cout<<(mp[i][j]==-1?"*":to_string(mp[i][j]));
			}
			cout<<endl;
		}
		end=true;
	}
	return 0;
}