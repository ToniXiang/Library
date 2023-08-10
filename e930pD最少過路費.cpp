#include<iostream>
#include<vector>
#include<limits>
#include<unordered_map>
//AC (6.4s, 26.2MB)
using namespace std;
typedef long long ll;
struct Data
{
    ll end;
    ll cost;
    ll rd;
};
int n,m,k;
const ll INF=numeric_limits<ll>::max();
ll r=INF;
unordered_map<int,vector<Data>>mp;
void dfs(ll cur,int path,ll total){
    if (path>=k||total>=r)return;
    for(auto& it:mp[cur]){
        ll newrd=it.cost+total;
        if(it.rd>newrd){
            it.rd=newrd;
            if(it.end==n&&path<k){
                r=min(r,newrd);
                return;
            }
            dfs(it.end,path+1,newrd);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    ll a,b,c;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        mp[a].push_back({b,c,INF});
    }
    n-=1;
    dfs(0,0,0);
    cout<<(r==INF?"impossible":to_string(r))<<endl;
    return 0;
}