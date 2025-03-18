#include<iostream>
using namespace std;
typedef long long ll;
int main(){
	ll n;
	while(cin>>n){
		if(n==0)break;
		int rd=0;
		string s="";
		while(n>0){
			if((n&0x01)==1){
				rd++;
				s="1"+s;
			}
			else s="0"+s;
			n>>=1;
		}
		cout<<"The parity of "<<s<<" is "<<rd<<" (mod 2)."<<endl;
	}
	return 0;
}
// 把輸入的數字轉換成二進制，然後再計算二進制中 1 的個數