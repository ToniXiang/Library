#include<iostream>
#include<vector>
#include<limits>
#include<queue>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef pair<ll,pair<int,int>> plpii;
const ll INF=numeric_limits<ll>::max();
struct Data{
    ll tail; //到站編號
    ll cost; //花費票價
    int path;//地鐵名稱(0號地鐵或1號地鐵)
};
int n,m1,m2;//地鐵個數、0號地鐵個數、1號地鐵個數
ll s,t;
unordered_map<int,vector<Data>>mp;
void dijkstra(){
    //NA (score:65%) 我不知道，先放著。
    //找 s 到 t 的最短路徑，最多只能轉乘一次。
    //DP[n][0~3]來處理極值的情況:
    //DP[n][0]=只用0號鐵路、DP[n][1]=只用1號鐵路、DP[n][2]=0號鐵路轉乘一次到1號鐵路、
    //DP[n][3]=1號鐵路轉乘一次到0號鐵路，並非代表0次1次2次3次的轉乘情況。
    //DP+Dijkstra的轉移判斷:
    vector<vector<ll>> DP(n, vector<ll>(4, INF));
    DP[s][0] = DP[s][1] = DP[s][2] = DP[s][3] = 0;
    priority_queue<plpii, vector<plpii>, greater<plpii>> pq;
    pq.push({0, {s, 0}});
    pq.push({0, {s, 1}});
    pq.push({0, {s, 2}});
    pq.push({0, {s, 3}});
    while (!pq.empty()) {
        ll cost=pq.top().first;
        int u=pq.top().second.first;
        int used_transfer=pq.top().second.second;
        pq.pop();
        if (cost>DP[u][used_transfer]) continue;
        for (const Data& d:mp[u]){
            int new_used_transfer=used_transfer + d.path;
            if(new_used_transfer>3)continue;//最多轉乘一次
            //如果已經轉過一次，不可以再次轉乘!
            if(used_transfer==1&&new_used_transfer==2)continue;
            if(used_transfer==2&&new_used_transfer==1)continue;
            if(cost+d.cost<=DP[d.tail][new_used_transfer]) {
                DP[d.tail][new_used_transfer]=cost+d.cost;
                pq.push({DP[d.tail][new_used_transfer],{d.tail,new_used_transfer}});
            }
        }
    }
    ll min_cost=min(min(DP[t][0],DP[t][1]),min(DP[t][2],DP[t][3]));
    cout << min_cost << endl;
}
int main()
{
    cin>>n>>m1>>m2;
    mp.reserve(m1+m2);
    ll u,v,c;//起點的站點編號、終點的站點編號、花費的票價
    for(int i=0;i<m1+m2;i++){
        cin>>u>>v>>c;
        mp[u].push_back({v,c,(i<m1?0:1)});//u和v連接，雙向圖
        mp[v].push_back({u,c,(i<m1?0:1)});
    }
    cin>>s>>t;
    dijkstra();
    return 0;
}