#include<iostream>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
    if(a==1)return b;
    else return a%b==0?b:gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(false);
    ll n;
    while(cin>>n&&n!=0){
        ll res=0;
        for(ll i=1;i<n;i++){
            for(ll j=i+1;j<=n;j++){
                res+=gcd(j,i);
            }
        }
        cout<<res<<endl;
    }
    return 0;
}