#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
// NA (score:74%) 可能有座標在界外要處理
/*
6
3 9 10 6
5
1 9 5 6
1
1 1 1 1
*/
ll N;
int rs(int x, int y)
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
int main()
{
    int n, x1, y1, x2, y2, x3, y3, x4, y4, t, k;
    ll s;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    N = n * 2 - 1;
    x1 -= n, y1 -= n, x2 -= n, y2 -= n; // 原點轉成 (0, 0)
    s = min(x1, x2) <= 0 && 0 <= max(x1, x2) &&
        min(y1, y2) <= 0 && 0 <= max(y1, y2); // 是否包含原點
    for (k = 0; k < 4; k++)
    {                                           // 4 個象限
        x4 = max(max(0, x1), max(0, x2)) + 1;   // 切第一象限範圍：
        y4 = max(max(-1, y1), max(-1, y2)) + 1; //(x3+1, y3+1)-(x4, y4)
        x3 = min(max(1, x1), max(1, x2));       // 原點轉成 (1, 1)
        y3 = min(max(0, y1), max(0, y2));       // 不含 Y 軸
        s += rs(x4, y4) - rs(x4, y3) - rs(x3, y4) + rs(x3, y3);
        t = -x1, x1 = y1, y1 = t; // 轉90度
        t = -x2, x2 = y2, y2 = t;
    }
    cout << s << endl;
}