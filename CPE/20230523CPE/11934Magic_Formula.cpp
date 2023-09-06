#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int a,b,c,d,l;
    while (cin>>a>>b>>c>>d>>l)
    {
        if(a==0&&b==0&&c==0&&d==0&&l==0)break;
        int r=0;
        for(int i=0;i<=l;i++){
            int val=a*i*i+b*i+c;
            if(val%d==0)r++;
        }
        cout<<r<<endl;
    }
    return 0;
}