#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    ll a,b;
    cin>>n;
    vector<pii>v;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),[](pii x,pii y){return x.first*y.second>=y.first*x.second;});
    ll m=0,result=0;
    for(int i=0;i<n;i++){
        m+=v[i].second;
        result+=v[i].first*m;
    }
    cout<<result<<endl;
    return 0;
}