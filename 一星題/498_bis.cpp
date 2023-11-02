#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    ll x,a;
    string buf;
    while(getline(cin,buf)){
        x=stoi(buf.c_str());
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