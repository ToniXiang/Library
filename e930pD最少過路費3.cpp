#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
using namespace std;
//AC (1.1s, 20.5MB)
typedef long long ll;
struct Data
{
    ll end;
    ll cost;
};
const ll INF = numeric_limits<ll>::max();
int n, m, k;
ll r = INF;
unordered_map<int,vector<Data>> mp;
void dp() {
    vector<vector<ll>> dp(n, vector<ll>(k + 1, INF));
    dp[0][0] = 0;
    for (int steps = 0; steps <= k; steps++) {
        for (int i = 0; i < n; i++) {
            if (dp[i][steps] == INF)
                continue;
            for (const auto& neighbor : mp[i]) {
                if (steps + 1 <= k) {
                    dp[neighbor.end][steps + 1] = min(dp[neighbor.end][steps + 1], dp[i][steps] + neighbor.cost);
                }
            }
        }
    }
    for (int steps = 0; steps <= k; steps++) {
        r = min(r, dp[n - 1][steps]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    ll a, b, c;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        mp[a].push_back({b, c});
    }
    dp();
    cout << (r == INF ? "impossible" : to_string(r)) << endl;
    return 0;
}