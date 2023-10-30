#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
using namespace std;
//	AC (0.9s, 19.9MB)
typedef long long ll;
struct Data
{
    ll name;
    ll cost;
};
const ll INF = numeric_limits<ll>::max();
int main() {
    ios_base::sync_with_stdio(false);
    int n, m, k;
    ll a, b, c;
    vector<vector<Data>>mp;
    cin >> n >> m >> k;
    mp.resize(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        mp[a].push_back({b, c});
    }
    vector<vector<ll>> dp(n, vector<ll>(k + 1, INF));
    dp[0][0] = 0;
    for (int step = 0; step <= k; step++) {
        for (int i = 0; i < n; i++) {
            if (dp[i][step] == INF)
                continue;
            for (const auto& next : mp[i]) {
                if (step + 1 <= k) {
                    dp[next.name][step + 1] = min(dp[next.name][step + 1], dp[i][step] + next.cost);
                }
            }
        }
    }
    ll r = INF;
    for (int step = 0; step <= k; step++) {
        r = min(r, dp[n - 1][step]);
    }
    cout << (r == INF ? "impossible" : to_string(r)) << endl;
    return 0;
}