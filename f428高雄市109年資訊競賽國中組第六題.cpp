#include <iostream>
using namespace std;
typedef long long ll;
// AC (3ms, 332KB)
/*
6
3 9 10 6
5
1 9 5 6
1
1 1 1 1
*/
ll N;
ll rs(ll x, ll y)
{
    if (x > y)
        swap(x, y);
    if (x > N)
        x = N;
    if (y > N)
        y = N;
    x -= 1;
    ll sum = x * (x + 1) * (x + 2) / 6;
    ll sum1 = y == 1 ? 1 : (y + 1) * y / 2;
    return sum1 * (x + 1) + sum;
}
ll check(ll i)
{
    if (i < 1)
        return 1;
    if (i > N)
        return N;
    return i;
}
int main()
{
    auto get_max = [](ll a, ll b) -> ll
    {
        return (a > b) ? a : b;
    };
    auto get_min = [](ll a, ll b) -> ll
    {
        return (a < b) ? a : b;
    };
    ll n, x1, y1, x2, y2, x3, y3, x4, y4, t, k, s;
    while (cin >> n >> x1 >> y1 >> x2 >> y2)
    {
        N = n * 2 - 1;
        x1 = check(x1);
        y1 = check(y1);
        x2 = check(x2);
        y2 = check(y2);
        x1 -= n, y1 -= n, x2 -= n, y2 -= n; // 原點轉成 (0, 0)
        s = get_min(x1, x2) <= 0 && 0 <= get_max(x1, x2) &&
            get_min(y1, y2) <= 0 && 0 <= get_max(y1, y2); // 是否包含原點
        for (k = 0; k < 4; k++)
        {                                                       // 4 個象限
            x4 = get_max(get_max(0, x1), get_max(0, x2)) + 1;   // 切第一象限範圍：
            y4 = get_max(get_max(-1, y1), get_max(-1, y2)) + 1; //(x3+1, y3+1)-(x4, y4)
            x3 = get_min(get_max(1, x1), get_max(1, x2));       // 原點轉成 (1, 1)
            y3 = get_min(get_max(0, y1), get_max(0, y2));       // 不含 Y 軸
            s += rs(x4, y4) - rs(x4, y3) - rs(x3, y4) + rs(x3, y3);
            t = -x1, x1 = y1, y1 = t; // 轉90度
            t = -x2, x2 = y2, y2 = t;
        }
        cout << s << endl;
    }
}