//  AC (3ms, 364KB)
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
constexpr int N=1E3+1; 
vector<int>primes;
vector<int> dp(N, -1);
bool bs(int left,int right,int key){
    if(left>right)return false;
    int mid=left+(right-left)/2;
    if(primes[mid]==key)return true;
    else if(primes[mid]<key)return bs(mid+1,right,key);
    else return bs(left,mid-1,key);
}
int dfs(int len){
    if (len == 2 || len == 3) return 0;
    if (dp[len] != -1) return dp[len];
    int min_cost = INT_MAX;
    for (int i = 0; i < primes.size(); ++i) {
        if (primes[i] >= len) break;
        if (bs(0, primes.size() - 1, len - primes[i])) {
            int cost = dfs(primes[i]) + dfs(len - primes[i]) + len;
            min_cost = min(min_cost, cost);
        }
    }
    return dp[len] = (min_cost == INT_MAX) ? 0 : min_cost;
}
int main() {
    ios_base::sync_with_stdio(false);
    vector<bool>is_prime(N,true);
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i*i<N;++i){
        if(is_prime[i]){
        for(int j=i*i;j<N;j+=i){
            is_prime[j]=false;
            }
        }
    }
    for(int i=2;i<N;i++){
        if(is_prime[i])primes.push_back(i);
    }
    int n;
    while(cin>>n){
        cout<<dfs(n)<<endl;
    }
    return 0;
}