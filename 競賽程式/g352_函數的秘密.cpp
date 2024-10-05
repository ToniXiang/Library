//	NA (score:30%)
#include<iostream>
#include<bitset>
using namespace std;
typedef long long ll;
constexpr ll MOD=998244353;
ll countPrefixOnes(const string& n) {
    ll ans = 0;
    int len = n.length();
    for (int d = 1; d <= len; ++d) {
        for (int o = 1; o <= d; ++o) {
            string l_str = string(o, '1') + string(d - o, '0');
            string r_str = string(o, '1') + string(d - o, '9');
            if (l_str.length() > len || (l_str.length() == len && l_str > n)) continue;
            if (r_str.length() > len || (r_str.length() == len && r_str > n)) r_str = n;
            
            ll l = 0, r = 0;
            for (char c : l_str) l = (l * 10 + (c - '0')) % MOD;
            for (char c : r_str) r = (r * 10 + (c - '0')) % MOD;
            
            ll num_n = 0;
            for (char c : n) num_n = (num_n * 10 + (c - '0')) % MOD;
            
            ll diff = (min(num_n, r) - min(num_n, l-1) + MOD) % MOD;
            ans = (ans + diff) % MOD;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    string s;
    while(cin>>n>>s){
        cout<<countPrefixOnes(s)<<endl;
    }
    return 0;
    //12
    //01 10 11 12
    //5
    //
    //12345678901234567899
    //835063284
}