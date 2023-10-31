#include<iostream>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    string s;
    ll total=0;
    while(cin>>s){
        if(s=="0")break;
        while(s.size()!=1){
            total=0;
            for(char it:s){
                total+=(it-'0');
            }
            s=to_string(total);
        }
        cout<<s<<endl;
    }
    return 0;
}