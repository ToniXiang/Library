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
// 這題是計算數字的每個位數的和，如果和大於等於10則繼續計算，直到和小於10為止