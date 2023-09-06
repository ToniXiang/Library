#include<iostream>
#include<vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n,n1;
    char del,del1;
    cin>>n;
    vector<vector<int>>mp(101,vector<int>(101,0));
    for(int i=0;i<n;i++){
        cin>>del>>del1>>n1;
        bool fg=false;
        for(int j=0;j<n1;j++){
            for(int k=0;k<n1;k++){
                cin>>mp[j][k];
                if(mp[j][k]<0)fg=true;
            }
        }
        for(int j=0;j<n1;j++){
            if(fg)break;
            for(int k=0;k<n1;k++){
                if(mp[j][k]!=mp[n1-j-1][n1-k-1]){
                    fg=true;
                    break;
                }
            }
        }
        cout<<"Test #"+to_string(i+1)+": "+(fg?"Non-symmetric":"Symmetric")+"."<<endl;
    }
    return 0;
}