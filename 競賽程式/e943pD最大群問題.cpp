// AC (10ms, 16.3MB)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<vector<int>> friends;
vector<int> dp;
// mask: 二進位表示目前選擇的人
// dp[mask]: 目前選擇的人中最多有幾個人是朋友
// 轉移方程: dp[mask] = max(1 + dp[mask | (1 << i)]) for i in 0 to N-1
// 代表選擇第 i 個人，並且他是朋友的話，就可以選擇他
int solve(int mask) {
    if(dp[mask] != -1) return dp[mask];
    int res = 0;
    for(int i = 0; i < N; ++i) {
        if(!(mask & (1 << i))) {
            bool ok = true;
            for(int j = 0; j < N; ++j) { 
                if(mask & (1 << j) && !friends[i][j]) {
                    ok = false;
                    break;
                }
            }
            if(ok) res = max(res, 1 + solve(mask | (1 << i)));
        }
    }
    return dp[mask] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    friends.assign(N, vector<int>(N, 0));
    dp.assign(1 << N, -1);
    for(int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        // 朋友關係是雙向的
        friends[a][b] = friends[b][a] = 1;
    }
    cout << solve(0) << endl;
    return 0;
}