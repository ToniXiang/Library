#include<iostream>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    ll x,y,x1,y1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>y>>x1>>y1;
        ll start=x+y;
        ll end=x1+y1;
        ll total=((1+end)*end/2+x1)-((1+start)*start/2+x);
        cout<<"Case "<<i<<": "<<total<<endl;
    }
    return 0;
}