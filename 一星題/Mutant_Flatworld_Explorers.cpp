#include<iostream>
#include<vector>
using namespace std;
string dir="NESW";
pair<int,int>moved[4]={{0,1},{1,0},{0,-1},{-1,0}};// N{0,1} S{0,-1}
int main(){
	int n,m;
	string s;
	while(cin>>n>>m){
		int x,y;
		char d;
		vector<vector<int>> mp(n+1, vector<int>(m+1,0));
		while(cin>>x>>y>>d>>s){
			int cur_dir=dir.find(d);
			bool fg=false;
			for(const char&it:s){
				if(it=='L'){
					if(--cur_dir==-1)cur_dir=3;
				}
				else if(it=='R'){
					if(++cur_dir==4)cur_dir=0;
				}
				else{//'F'
					x+=moved[cur_dir].first;
					y+=moved[cur_dir].second;
					if(x<0||y<0||x>n||y>m){
						x-=moved[cur_dir].first;
						y-=moved[cur_dir].second;
						if(mp[x][y]==1)continue;
                	    mp[x][y]=1;
                		fg=true;
						break;
					}
				}
			}
			cout<<x<<" "<<y<<" "<<dir[cur_dir]<<(fg?" LOST":"")<<endl;
		}
	}
	return 0;
}
// 同一地方越界不會再發生
// if 越界 => LOST 並記錄
// if 越界但曾在同一地方 => 回溯到上一個位置