#include<iostream>
using namespace std;
int main(){
	string s;
	char num[100][100]={' '};
	for(int x=0;x<100;x++){
		for(int y=0;y<100;y++){
			num[x][y]=' ';
		}
	}
	int rd=0,len=0;
	while(getline(cin,s)){
		if(s=="")break;
		for(int j=0;j<s.size();j++){
			num[rd][j]=s[j];
		}
		rd++;
		len=max(len,(int)s.size());
	}
	for(int x=0;x<len;x++){
		for(int y=rd-1;y>=0;y--){
			cout<<num[y][x];
		}
		cout<<endl;
	}
	return 0;
}
// 紀錄每行的字串，並找出最長的字串長度
// 然後依序輸出每行的第 i 個字元，若該行沒有第 i 個字元則輸出空白。
// input(行):
// s1
// s2
// s3
// output(列):
// s3 s2 s1