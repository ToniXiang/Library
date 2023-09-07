#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll fpow(ll p,ll q){
    if(q==0)return 1;
    if(q==1)return p;
    if((q%2)==1)return p*fpow(p*p,q/2);
    return fpow(p*p,q/2);
}
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    ll n1;
    cin>>n;
    for(int i=0;i<n;i++){
        vector<ll>v;
        while (cin>>n1)
        {
            if(n1==0)break;
            v.push_back(n1);
        }
        sort(v.begin(),v.end(),[](ll a,ll b){return a>b;});
        ll r=0;
        for(int j=0;j<v.size();j++){
            r+=fpow(v[j],j+1);
        }
        r*=2;
        cout<<(r>=5E6?"Too expensive":to_string(r))<<endl;
    }
    return 0;
}