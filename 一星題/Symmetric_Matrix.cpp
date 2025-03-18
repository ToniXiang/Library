#include<iostream>
using namespace std;
int main(){
	int n,m;
	char buf,buf1;
	while(cin>>n){
		for(int rd=1;rd<=n;rd++){
			cin>>buf>>buf1>>m;
			int num[m][m]={0};
			for(int i=0;i<m;i++){
				for(int j=0;j<m;j++){
					cin>>num[i][j];
				}
			}
			bool fg=true;
			for(int i=0;i<m;i++){
				for(int j=0;j<m;j++){
					if(num[m-1-i][m-1-j]!=num[i][j]||num[i][j]<0){
						fg=false;
						break;
					}
				}
				if(!fg)break;
			}
			cout<<"Test #"<<rd<<": "<<(fg?"Symmetric.":"Non-symmetric.")<<endl;
		}
	}
	return 0;
}