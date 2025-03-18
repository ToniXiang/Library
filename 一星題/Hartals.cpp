#include<iostream>
#include<set>
using namespace std;
int main(){
	int n,p,h,a;
	while(cin>>n){
		while(n--){
			cin>>p;
			cin>>h;
			set<int>st;
			while(h--){
				cin>>a;
				for(int i=a;i<=p;i+=a){
					if((i+6)%7==5||(i+6)%7==6)continue;
					if(!st.count(i))st.insert(i);
				}
			}
			cout<<st.size()<<endl;
		}
	}
	return 0;
}
