#include<iostream>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    ll a,b;
    while(cin>>a>>b){
        if(a==0&&b==0)break;
        int cy=0,res=0;
        while(a>0||b>0){
            int sum=a%10+b%10+cy;
            if(sum>=10)cy=1,res+=1;
            else cy=0;
            a/=10;
            b/=10;
        }
        if(res==0)cout<<"No carry operation."<<endl;
        else cout<<(res==1?"1 carry operation.":to_string(res)+" carry operations.")<<endl;
    }
    return 0;
}