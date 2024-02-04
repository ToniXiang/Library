#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

pair<ll,ll> get(ll v) {
    ll k = ceil(sqrt(v));
    ll m = k * k - k + 1;
    bool isOdd = k % 2 == 1;
    if (v == m) {
        return {k, k};
    } else if (v >= m) {
        if (isOdd) {
            return {k * k - v + 1, k};
        }
        return {k, k * k - v + 1};
    } else {
        if (isOdd) {
            return {k, k - (m - v)};
        }
        return {k - (m - v), k};
    }
}

int main() {
    ios::sync_with_stdio(0);
    ll v;
    while (cin>>v) {
        if (v == 0)break;
        pair<ll,ll> ans = get(v);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}