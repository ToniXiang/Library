#include<iostream>
#include<math.h>
using namespace std;
typedef long long ll;
bool check(ll v){
    if(v==2||v==3)return true;
    ll m=v%6;
    if(m!=1&&m!=5)return false;
    ll sq=(ll)sqrt(v);
    for(ll i=5;i<=sq;i+=6){
        if(v%i==0||v%(i+2)==0)return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    ll n;
    while(cin>>n){
        if(!check(n))cout<<n<<" is not prime."<<endl;
        else{
            ll n_rev=0,tmp=n;
            while(tmp>0){
                n_rev=n_rev*10+tmp%10;
                tmp/=10;
			}
            cout<<n<<((n!=n_rev&&check(n_rev))?" is emirp.":" is prime.")<<endl;
        }
    }
    return 0;
}