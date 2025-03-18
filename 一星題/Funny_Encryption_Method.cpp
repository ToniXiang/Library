#include<iostream>
#include<sstream>
#include<iomanip>
using namespace std;
int main(){
	int n,m;
	int num[]={0,1,1,2,1,2,2,3,1,2};
	while(cin>>n){
		while(n--&&cin>>m){
			int h16=0;
			string a=to_string(m);
			for(const char&it:a){
				h16+=num[it-'0'];
			}
			int b2=0;
			int b=m;
			while(b!=0){
				if((b&0x01))b2++;
				b>>=1;
			}
			cout<<b2<<" "<<h16<<endl;
		}
	}
	return 0;
}

// 265(decimal)=100001001(binary) => b1=3
// 265(hexadecima)==[0010][0110][0101](binary) => b2=5