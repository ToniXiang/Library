#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    ll x,a;
    string buf;
    while(cin>>x){
        cin.ignore();
        getline(cin,buf);
        stringstream ss(buf);
        vector<ll>v;
        while(getline(ss,buf,' '))
        {
            v.push_back(stoi(buf.c_str()));
        }
        v.pop_back();
        ll res=0,m=1;
        for(int i=v.size()-1;i>=0;i--){
            res+=v[i]*(v.size()-i)*m;
            m*=x;
        }
        cout<<res<<endl;
    }
    return 0;
}
// 輸入：
// x
// a[0] a[1] a[2] ... a[n]
// 題目：輸出方程式一次微分後帶入 x 的結果
// a[0]*(n - 0)*x^(n−1) + a[1]*(n − 1)*x^(n−2) + . . .+a[n-1]