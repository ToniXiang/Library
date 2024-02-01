#include<iostream>
#include<vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int m,n,cnt=0;
    char c;
    while(cin>>m>>n){
        if(m==0&&n==0) break;
        int mp[m][n];
        vector<pair<int,int>> rd;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>c;
                if(c=='*') mp[i][j]=-1,rd.push_back({i,j});
                else mp[i][j]=0;
            }
        }
        for(const auto i:rd){
            int cnt=0;
            for(int j=i.first-1;j<=i.first+1;j++){
                for(int k=i.second-1;k<=i.second+1;k++){
                    if(j>=0&&j<m&&k>=0&&k<n&&mp[j][k]!=-1)mp[j][k]++;
                }
            }
        }
        cout<<"Field #"<<++cnt<<":"<<endl;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mp[i][j]==-1) cout<<"*";
                else cout<<mp[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}