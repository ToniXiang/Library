#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,m,a;
	while(cin>>n){
		while(n--){
			cin>>m;
			vector<int>v;
			for(int i=0;i<m;i++){
				cin>>a;
				v.push_back(a);
			}
			int total=0;
			// dont use #include<alorithm> sort. it is faster than this sort.
			for(int i=0;i<m;i++){
				for(int j=i+1;j<m;j++){
					if(v[i]>v[j]){
						total++;
						int tmp=v[i];
						v[i]=v[j];
						v[j]=tmp;
					}
				}
			}
			cout<<"Optimal train swapping takes "<<total<<" swaps."<<endl;
		}
	}
	return 0;
}