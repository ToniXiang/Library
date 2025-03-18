#include<iostream>
#include<set>
#include<sstream>
using namespace std;
int main(){
	int n,a;
	string s;
	while(getline(cin,s)){
		stringstream ss(s);
		ss>>n;
		int rd=0;
		set<int>st;
		bool fg=true;	
		int head,tail;
		ss>>head;
		for(int i=1;i<n;i++){
			ss>>tail;
			int cur=abs(head-tail);
			if(st.count(cur))fg=false;
			else st.insert(cur);
			head=tail;
		}
		if(fg){
			int sq=1;
			for(const int& it:st){
				if(sq++!=it){
					fg=false;
					break;
				}
			}
		}
		cout<<(fg?"Jolly":"Not jolly")<<endl;
	}
	return 0;
}
// 輸入一個數列，判斷是否為 Jolly 數列
// Jolly 數列定義為：數列中相鄰兩數的差的絕對值為 1~n-1
// input：n v0、v1、v2、...、vn-1