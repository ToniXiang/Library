#include<iostream>
#include<math.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    ll n;
    while(cin>>n){
        ll len=sqrt(n);
        ll i=2;
        ll res_a=1;
        while(i<=len){
            if(n%(i*i)==0){
                res_a*=i;
                n/=(i*i);
                if(n==1)break;
            }
            else{
                i++;
            }
        }
        cout<<(res_a!=1?to_string(res_a):"")<<(res_a!=1&&n!=1?" ":"")<<(n!=1?"sqrt("+to_string(n)+")":"")<<endl;
    }
    return 0;
}