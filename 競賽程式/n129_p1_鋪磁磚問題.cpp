//  AC (3ms, 360KB)
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
// 遞迴解 會超時 O(3^n)
void f(int index,int&ans,const int& n){
    if(index==n){
        ans++;
        return;
    }
    for(int i=1;i<=3;++i){
        if(index+i<=n){
            f(index+i,ans,n);
        }
    }
}
// DP解 O(n)
// dp[i] = dp[i-1]+dp[i-2]+dp[i-3]
// dp[0]=1 初始值
// 推導出 dp[1]=1 dp[2]=2 dp[3]=4
void f2(const ll& n){
    vector<ll>dp(n+1,0);
    dp[0]=1;
    for(ll i=1;i<=n;++i){
        if(i-1>=0){
            dp[i]+=dp[i-1];
        }
        if(i-2>=0){
            dp[i]+=dp[i-2];
        }
        if(i-3>=0){
            dp[i]+=dp[i-3];
        }
    }
    cout<<dp[n]<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    f2(n);
    return 0;
}