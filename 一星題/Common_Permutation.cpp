#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
	string a,b;
	while(getline(cin,a)&&getline(cin,b)){
		unordered_map<char,int>ump;
		unordered_map<char,int>ump1;
		for(char&i:a){
			if(i==' ')continue;
			ump[i]++;
		}
		for(char&i:b){
			if(i==' ')continue;
			ump1[i]++;
		}
		string s="";
		for(char i='a';i<='z';i++){
			if(ump.count(i)&&ump1.count(i)){
				// string buf(要重複幾次,字元);
				string buf(min(ump[i],ump1[i]),i);
				s+=buf;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
// 輸出：兩個字串中共同的字母，並且按照字母順序輸出