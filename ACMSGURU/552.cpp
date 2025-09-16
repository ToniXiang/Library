// Problem: 552. Database optimization
// Contest: Codeforces - acm.sgu.ru archive
// URL: https://codeforces.com/problemsets/acmsguru/problem/99999/552
// Memory Limit: 262 MB
// Time Limit: 3000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

string makeKey(vector<string> &v)
{
    sort(v.begin(), v.end());
    string key;
    for (int i = 0; i < (int)v.size(); i++)
    {
        if (i > 0)
            key.push_back('&');
        key += v[i];
    }
    return key;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    unordered_map<string, int> ump;
    // 處理物件
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vector<string> v(m);
        for (int j = 0; j < m; j++)
            cin >> v[j];
        // 枚舉所有子集
        int subsets = 1 << m;
        for (int mask = 1; mask < subsets; mask++)
        {
            vector<string> subset;
            for (int b = 0; b < m; b++)
            {
                if (mask & (1 << b))
                    subset.push_back(v[b]);
            }
            string key = makeKey(subset);
            ump[key]++;
        }
    }
    // 查詢集合
    int q;
    cin >> q;
    while (q--)
    {
        int l;
        cin >> l;
        vector<string> query(l);
        for (int i = 0; i < l; i++)
            cin >> query[i];

        string key = makeKey(query);
        cout << ump[key] << "\n";
    }
    return 0;
}

/*
前面建表:處理物件 → 所有子集都加 1
後面查詢:查詢集合 → 直接在 map 查次數
例如：
查詢 {'ht=3','width=5'}
對應 {'width=5','ht=3','len=10'} {'name=sqr,'width=5','ht=3'}
雖然順序不對，但剛好能包含查詢的物件，稱子集合
Accepted 2859 ms 92800 KB
*/