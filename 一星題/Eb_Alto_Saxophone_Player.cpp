#include<iostream>
#include<map>
#include<vector>
using namespace std;
void f(int n,vector<int>&v){
	int i=0;
	while(n>0){
		if((n&0x01))v[i]++;
		n>>=1;
		i++;
	}
}
int main(){
	map<char,int>mp;
	mp['c']=0b0111001111;
	mp['d']=0b0111001110;
	mp['e']=0b0111001100;
	mp['f']=0b0111001000;
	mp['g']=0b0111000000;
	mp['a']=0b0110000000;
	mp['b']=0b0100000000;
	mp['C']=0b0010000000;
	mp['D']=0b1111001110;
	mp['E']=0b1111001100;
	mp['F']=0b1111001000;
	mp['G']=0b1111000000;
	mp['A']=0b1110000000;
	mp['B']=0b1100000000;
	int n;
	string s;
	while(cin>>n){
		while(n--){
		cin>>s;
		vector<int>v={0,0,0,0,0,0,0,0,0,0};
		f(mp[s[0]],v);
		for(int i=1;i<s.size();i++){
			f(((~mp[s[i-1]])&mp[s[i]]),v);
		}
		for(int i=v.size()-1;i>=0;i--){
			cout<<v[i]<<(i==0?"":" ");
		}
		cout<<endl;
		}
	}
	return 0;
}
