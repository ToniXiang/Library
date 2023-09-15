#include <iostream>
#include <set>
#include <numeric>
#include <algorithm>
using namespace std;
#define a s[i].begin()
#define b s[i].end()
#define c s[j].begin()
#define d s[j].end()
#define inst(xx) inserter(xx, xx.begin())
#define oper(ss) accumulate(ss.begin(), ss.end(), std::string())
int main()
{
    ios_base::sync_with_stdio(false);
    int n, counter = 0;
    while (cin >> n)
    {
        if (n == 0)
            break;
        string s[n];
        cout << "Test Case " << ++counter << ":" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            sort(s[i].begin(), s[i].end());
            cout << (char)('A' + i) << ": {" << s[i]<<"}" << endl;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                set<char> us; // A與B聯集(union)
                set_union(a, b, c, d, inst(us));
                cout << (char)('A' + i) << "+" << (char)('A' + j) << ": {" << oper(us) << "}" << endl;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                set<char> si; // A與B交集(intersection)
                set_intersection(a, b, c, d, inst(si));
                cout << (char)('A' + i) << "*" << (char)('A' + j) << ": {" << oper(si) << "}" << endl;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                set<char> sd; // A與B差集(difference)
                set_difference(a, b, c, d, inst(sd));
                cout << (char)('A' + i) << "-" << (char)('A' + j) << ": {" << oper(sd) << "}" << endl;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                int rd = 0;
                for (int k = 0; k < s[j].size(); k++)
                {
                    if (find(s[i].begin(), s[i].end(), s[j][k]) != s[i].end())
                        rd++;
                }
                cout << (char)('A' + i) << (rd == s[j].size() ? " contains " : " does not contain ") << (char)('A' + j) << endl;
            }
        }
    }
    return 0;
}