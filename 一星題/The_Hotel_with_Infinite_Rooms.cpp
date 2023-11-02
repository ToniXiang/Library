#include<iostream>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    ll a,b;
    while(cin>>a>>b){
        while(b>0){
            b-=(a++);
        }
        cout<<a-1<<endl;
    }
    return 0;
}