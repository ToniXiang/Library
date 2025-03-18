#include<iostream>
using namespace std;
int main(){
	string s;
	bool fg=false;
	while(getline(cin,s)){
		string res="";
		for(char&i:s){
			if(i=='\"'){
				res+=(fg?"\'\'":"``");
				fg^=0x01;
			}
			else res+=i;
		}
		cout<<res<<endl;
	}
	return 0;
}
// Quotes(引號)
// 輸出時將雙引號(")轉換為前後關係的反引號(``)和單引號('')。