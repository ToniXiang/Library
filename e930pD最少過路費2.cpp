#include <iostream>
#include <unordered_map>
#include <queue>
#include <limits>
//優化結果:超過記憶體限制，但時間快很多了
//進一步優化
//1.運用優先權佇列(priority_queue)的最小堆(heapmin)，提取下個節點會是最小那個。
//2.DFS 改 BFS 可以提早結束。我上個寫法(遞迴)則是找過所有節點，最後才輸出答案。
//3.dp[i][j] 從節點 0 到節點 i，使用 j 步所需的最小過路費，省去重複計算的時間。
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,pair<ll,int>> plpli;
struct Data
{
    ll end;
    ll cost;
    ll rd;
};
const ll INF=numeric_limits<ll>::max();
int n,m,k;
ll r=INF;
unordered_map<int,vector<Data>>mp;
void dijkstra() {
    vector<vl>dp(n,vl(k + 1, INF));
    priority_queue<plpli,vector<plpli>,greater<>> pq;
    dp[0][0]=0;
    pq.push({0,{0,0}});
    while(pq.size()>0) {
        auto cur=pq.top();
        pq.pop();
        ll cur_cost=cur.first;
        ll cur_node=cur.second.first;
        int steps=cur.second.second;
        if(steps>k||cur_cost>dp[cur_node][steps])continue;
        for(auto& it:mp[cur_node]){
            ll newrd=cur_cost+it.cost;
            if (newrd<dp[it.end][steps+1]){
                dp[it.end][steps+1]=newrd;
                pq.push({newrd,{it.end,steps+1}});
            }
        }
    }
    for(int i=0;i<=k;i++){
        r=min(r,dp[n-1][i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    ll a,b,c;
    cin>>n>>m>>k;
    for (int i= 0;i<m;i++) {
        cin>>a>>b>>c;
        mp[a].push_back({b,c,0});
    }
    dijkstra();
    cout<<(r==INF?"impossible":to_string(r))<<endl;
    return 0;
}