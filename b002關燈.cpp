#include<iostream>
#include<math.h>
#include<limits>
using namespace std;
//以 L[5]={1,-1,0,0,0} 與之反向組合而成
int moved[5][2] = {{1,0}, {-1,0}, {0,0}, {0,-1}, {0,1}};
const int INF=INT32_MAX;
struct data_map{
	//設12x12地圖 索引mp[0to11][0、11]、mp[0、11][0to11]為外邊界，防止索引超過陣列範圍
	bool mp[12][12];
	int C(int l, int s){
		for (int i=1;i<11;i++){
			if(mp[l - 1][i]){
				for(int j=0;j<5;j++){
					//~mp[l + moved[j][0]][i + moved[j][1]]
					mp[l + moved[j][0]][i + moved[j][1]] ^= 1;
				}
			s++;
		}
		}
		if(l == 10){
			for(int i=1;i<11;i++){
				//'#'為Flase 'O'為True
				if(mp[10][i])return INF;
			}
			//都無'o'的情況
			return s;
		}
		return C(l + 1, s);
	}
	int D(int l, int s){
		data_map y = *this;
		for(int i=0;i<5;i++){
			//~y.mp[1 + moved[i][0]][l + moved[i][1]]
			y.mp[1 + moved[i][0]][l + moved[i][1]] ^= 1;
		}
		if(l == 10)	return min(C(2, s), y.C(2, s + 1));
		else return min(D(l + 1, s), y.D(l + 1, s + 1));
	}
};
int main(){
	int t;
	string s;
	cin >> t;
	while(t--){
		data_map m;
		for(int i=1;i<11;i++){
			cin>>s;
			for(int j=1;j<11;j++){
				m.mp[i][j]=s[j-1]-'#';
			}
		}
		cout << m.D(1, 0) << endl;
	}
	return 0;
}