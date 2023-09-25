#include <iostream>
typedef long long type;
using namespace std;
//調和級數 數論
int main()
{
    ios::sync_with_stdio(false);
    type n,l,r;
    cin>>n>>l>>r;
    const type len=r-l+1;
    type ans[len]={0};
    type total=0;
    for(type i=1;i<=n;){
        type a=n/i;
        type x=a*i+1;
        if(x<=r){
            if(x<l){
                x+=(l-x)/a*a;
                if(x<l)x+=a;
                total+=(x-(a*i+1))/a;
            }
            while(x<=r){
                ans[x-l]++;
                x+=a;
            }
        }
        cout<<"i="<<i<<" a*i+1="<<a*i+1<<" a="<<a<<"\n";
        i=n/a+1;
    }
    for(int i=0;i<len;i++){
        total+=ans[i];
        cout<<total<<" ";
    }
    return 0;
}