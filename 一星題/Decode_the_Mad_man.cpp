#include<iostream>
#include<algorithm>// 用於 std::transform
#include<cctype>// 用於 ::tolower
using namespace std;
int main(){
	string arr="`1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./";
	string s;
	while(getline(cin,s)){
		// transform(開始和結束迭代器,存回原字串,[::tolower或::toupper])
		transform(s.begin(),s.end(),s.begin(),::tolower);
		string res="";
		for(char& i:s){
			int index=-1;
			for(int j=0;j<arr.size();j++){
				if(i==arr[j]){
					index=j;
					break;
				}
			}
			if(index==-1)res+=" ";
			else res+=arr[(index+44)%arr.size()];
		}
		cout<<res<<endl;
	}
	return 0;
}
//建表 依題目：解密為字串在鍵盤上左移兩位，空格不變