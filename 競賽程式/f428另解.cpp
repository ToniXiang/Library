#include <iostream>
using namespace std;
typedef long long ll;
//Rectangular area(rs)
//sum=1+3+6+10+...
//sum1=1+2+3+4+...
int main() {
    ll x,y;
    int n=3;
    while(cin>>x>>y)
    {
        if(x>y)swap(x,y);
        if(x>n)x=n;
        if(y>n)y=n;
        x-=1;
        ll sum=x*(x+1)*(x+2)/6;
        ll sum1=y==1?1:(y+1)*y/2;
        cout<<sum<<" "<<sum1<<endl;
        cout<<sum1*(x+1)+sum<<endl;
    }
    return 0;
}
