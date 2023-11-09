#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n,n1;
    char buf,buf1;
    while(cin>>n){
        int cnt=1;
        while(n--){
            cin>>buf>>buf1>>n1;
            int mp[n1][n1]={0};
            for(int i=0;i<n1;i++){
                for(int j=0;j<n1;j++){
                    cin>>mp[i][j];
                }
            }
            string res="Symmetric.";
            for(int i=0;i<n1;i++){
                for(int j=0;j<n1;j++){
                    if(mp[i][j]!=mp[n1-1-i][n1-1-j]){
                        res="Non-Symmetric.";
                        i=n1;
                        break;
                    }
                }
            }
            cout<<"Test #"<<cnt++<<": "<<res<<endl;
        }
    }
    return 0;
}