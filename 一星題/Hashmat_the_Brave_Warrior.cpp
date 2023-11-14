#include<iostream>
#include<math.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    ll a,b;
    while(cin>>a>>b){
        cout<<abs(a-b)<<endl;
    }
    return 0;
}