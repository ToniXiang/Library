#include<iostream>
using namespace std;
int main(){
	int rd,n,m,p,x,y;
	while(cin>>rd){
		while(rd--){
			cin>>n>>m>>p;
			cout<<n<<" "<<m<<" "<<p<<endl;
			char num[n][m]={0};
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					cin>>num[i][j];
				}
			}
			while(p--){
				cin>>x>>y;
				int r=1;
				int a=x,b=y,c=x,d=y;
				while(true){
					bool fg=false;
					if(--a<0||--b<0||++c>=n||++d>=m)break;
					for(int i=a;i<=c;i++){
						for(int j=b;j<=d;j++){
							if(num[i][j]!=num[x][y]){
								fg=true;
								break;
							}
						}
					}
					if(fg)break;
					r+=2;
				}
				cout<<r<<endl;
			}
		}
	}
	return 0;
}
/*
    在範圍內[1~n+1][1~m+1]，這樣就可以保證不會出界
    然後就是判斷是否是正方形了，如果是就再擴大一圈檢查
    如果不成正方形，跳出循環
*/