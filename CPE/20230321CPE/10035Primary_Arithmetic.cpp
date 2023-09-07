#include<iostream>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    ll a,b;
    while (cin>>a>>b)
    {
        if(a==0&&b==0)break;
        int r=0;
        int cy=0;
        int len=max(to_string(a).size(),to_string(b).size());
        int num[len]={0};
        for(int i=len-1;i>=0;i--){
            int sum=a%10+b%10+cy;
            cy=0;
            if(sum>=10){
                num[i]=sum-10;
                cy=1;
                r++;
            }
            else{
                num[i]=sum;
            }
            a/=10;
            b/=10;
        }
        cout<<(r==0?"No carry operation.":to_string(r)+" carry operations.")<<endl;
    }
    return 0;
}