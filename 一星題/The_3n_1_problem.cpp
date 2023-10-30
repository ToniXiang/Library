#include<iostream>
#include<math.h>
using namespace std;
typedef long long ll;
int f(int n,int res){
    if(n==1)return res+1;
    else if((n&1)==1)return f(3*n+1,res+1);
    else return f(n>>1,res+1);
}
int main() {
    ios_base::sync_with_stdio(false);
    ll a,b;
    while(cin>>a>>b){
        int res=0;
        if(a>b)a^=b,b^=a,a^=b;
        for(int i=a;i<=b;i++){
            res=max(res,f(i,0));
        }
        cout<<a<<" "<<b<<" "<<res<<endl;
    }
    return 0;
}