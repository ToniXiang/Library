#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n,amount,n1;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>amount;
        cin>>n1;
        vector<int>coins(n1,0);
        for(int j=0;j<n1;j++){
            cin>>coins[j];
        }
        vector<vector<int>>dp(n1+1,vector<int>(amount+1,0));
        for(int j=1;j<=n1;j++){
            for(int k=1;k<=amount;k++){
                dp[j][k]=dp[j-1][k];
                if(coins[j-1]<=k){
                    dp[j][k]=max(dp[j][k],dp[j-1][k-coins[j-1]]+coins[j-1]);
                }
            }
        }
        cout<<(dp[n1][amount]==amount?"YES":"NO")<<endl;
    }
    return 0;
}