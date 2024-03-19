#include<iostream>
using namespace std;
typedef long long ll;
ll getbin(string s){
    ll res=0,m=1;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='1')res+=m;
        m<<=1;
    }
    return res;
}
ll gcd(ll a,ll b){
    if(a==1)return b;
    else return a%b==0?b:gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    string a,b;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        cout<<"Pair #"<<i<<": "<<(gcd(getbin(a),getbin(b))>1?
        "All you need is love!":"Love is not all you need!")<<endl;
    }
    return 0;
}
// 輸入：
// n
// a1
// b2
// ...
// an
// bn
// 題目：輸入 n 組二進位數字，判斷兩數 a 、 b 的最大公因數是否大於 1