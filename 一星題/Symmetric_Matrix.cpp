#include<iostream>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    int n,n1,cnt=1;
    char buf;
    cin>>n;
    while(n--){
        cin>>buf>>buf>>n1;
        ll mp[n1][n1]={0};
        string res="Symmetric.";
        for(int i=0;i<n1;i++){
            for(int j=0;j<n1;j++){
                cin>>mp[i][j];
                if(mp[i][j]<0)res="Non-symmetric.";
            }
        }
        if(res=="Symmetric."){
            for(int i=0;i<n1;i++){
                for(int j=0;j<n1;j++){
                    if(mp[i][j]!=mp[n1-1-i][n1-1-j]){
                        res="Non-symmetric.";
                        i=n1;
                        break;
                    }
                }
            }
        }
        cout<<"Test #"<<cnt++<<": "<<res<<endl;
    }
    return 0;
}