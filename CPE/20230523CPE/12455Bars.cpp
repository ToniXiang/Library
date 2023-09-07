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
        vector<int>dp(amount+1,0);
        dp[0]=1;
        for(int j=0;j<n1;j++){
            for(int k=amount; k >= coins[j]; k--){
                dp[k]+=dp[k - coins[j]];
            }
        }
        cout<<(dp[amount]?"YES":"NO")<<endl;
    }
    return 0;
}