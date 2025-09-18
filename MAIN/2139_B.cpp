// Problem: B. Cake Collection
// Contest: Codeforces - Codeforces Round 1048 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2139/B
// Memory Limit: 512 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
	int n, a, b;
	cin >> n;
	while (n--)
	{
		cin >> a >> b;
		vector<int> v(a);
		for (int i = 0; i < a; i++)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		// for(auto it:v)cout<<it<<endl;
		ll res = 0;
		int area = min(a, b);
		for (int i = 0; i < area; i++)
		{
			res += v[a - 1 - i] * (ll)(b - i);
		}
		cout << res << endl;
	}
	return 0;
}
// 排序+貪心
// Accepted 265 ms 52 KB