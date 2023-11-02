#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n,a,b;
    while(cin>>n){
        int cnt=1;
        while(n--){
            cin>>a>>b;
            if((a&1)==0)a++;
            if((b&1)==0)b--;
            int rang=(b-a)/2+1;
            cout<<"Case "<<cnt++<<": "<<rang*(a+b)/2<<endl;
        }
    }
    return 0;
}