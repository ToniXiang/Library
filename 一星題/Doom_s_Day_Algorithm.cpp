#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int>v{0,31,28,31,30,31,30,31,31,30,31,30,31};
	vector<string>w{"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
	int n,a,b;
	while(cin>>n){
		while(n--){
			cin>>a>>b;
			int days=b;
			for(int i=0;i<a;i++){
				days+=v[i];
			}
			cout<<w[(days+4)%7]<<endl;
		}
	}
	return 0;
}
// 2011 年是一個，第一天從星期六開始
// 平年 2 月為 28 天，閏年的 2 月為 29 天