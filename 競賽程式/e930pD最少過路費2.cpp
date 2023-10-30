#include <iostream>
#include <vector>
#include <queue>
#include <limits>
//	NA (score:40%)
//1.運用優先權佇列(priority_queue)，提取下個節點會是最小花費。
//2.DFS 改 BFS 可以提早結束。我上個寫法(遞迴)則是找過所有節點，最後才輸出答案。
//3.dp[i][j] 從節點 0 到節點 i，使用 j 步所需的最小過路費，省去重複計算的時間。
using namespace std;
typedef long long ll;
typedef pair<ll,pair<ll,ll>> plpll;
struct Data
{
    ll name;
    ll cost;
};
const ll INF=numeric_limits<ll>::max();
int main() {
    ios_base::sync_with_stdio(false);
    ll a,b,c;
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<Data>>mp;
    mp.resize(n);
    for (int i= 0;i<m;i++) {
        cin>>a>>b>>c;
        mp[a].push_back({b,c});
    }
    vector<vector<ll>>dp(n,vector<ll>(k + 1, INF));
    priority_queue<plpll,vector<plpll>,greater<>> pq;
    dp[0][0]=0;
    // pq{花費，{城市編號，已經走了幾條路}} 對花費做優先權排列，存原點到此城市已經走了幾條路
    pq.push({0,{0,0}});
    while(pq.size()>0) {
        auto cur=pq.top();
        pq.pop();
        const ll cur_cost=cur.first;
        const ll cur_name=cur.second.first;
        const ll cur_step=cur.second.second;
        if(cur_step>k||cur_cost>dp[cur_name][cur_step])continue;
        for(const auto& next:mp[cur_name]){
            const ll next_cost=cur_cost+next.cost;
            if (next_cost<dp[next.name][cur_step+1]){
                dp[next.name][cur_step+1]=next_cost;
                pq.push({next_cost,{next.name,cur_step+1}});
            }
        }
    }
    ll r=INF;
    for(int i=0;i<=k;i++){
        r=min(r,dp[n-1][i]);
    }
    cout<<(r==INF?"impossible":to_string(r))<<endl;
    return 0;
}