#include<iostream>
using namespace std;
int getbin(int n){
    int res=0;
    while (n>0)
    {
        if((n&1)==1)res++;
        n>>=1;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    int n,a,b,c;
    cin>>n;
    while(n--){
        cin>>c;
        a=b=c;
        int res_b=0;
        while(b!=0){
            res_b+=getbin(b%10);
            b/=10;
        }
        cout<<getbin(a)<<" "<<res_b<<endl;
    }
    return 0;
}