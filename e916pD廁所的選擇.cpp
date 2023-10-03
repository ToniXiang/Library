#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
// 計算某個位置的最小距離
ll calculateMinDistance(ll n, ll k, ll position) {
    ll leftDist = position - 1;
    ll rightDist = n - position;
    return min(leftDist, rightDist);
}
// 計算某個位置的最大距離
ll calculateMaxDistance(ll n, ll k, ll position) {
    ll leftDist = position - 1;
    ll rightDist = n - position;
    return max(leftDist, rightDist);
}
// 二進位搜索，找到符合規則的位置
ll binarySearch(ll n, ll k) {
    ll left = 1;
    ll right = n;
    ll result = k;  // 預設結果為 k，即第 k 個廁所
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll minDist = calculateMinDistance(n, k, mid);
        ll maxDist = calculateMaxDistance(n, k, mid);
        if (minDist >= maxDist) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll n, k;
        cin >> n >> k;
        ll result = binarySearch(n, k);
        cout << result << endl;
    }
    return 0;
}
