#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int org_col, org_row, op, c1, c2, r1, r2, n, counter = 0;
    string s;
    while (cin >> org_row >> org_col)
    {
        cin >> op;
        int col = org_col, row = org_row;
        vector<vector<int>> gd(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                gd[i][j] = i * col + j;
            }
        }
        for (int i = 0; i < op; i++)
        {
            cin >> s;
            if (s == "EX")
            {
                cin >> r1 >> c1 >> r2 >> c2;
                swap(gd[r1 - 1][c1 - 1], gd[r2 - 1][c2 - 1]);
            }
            else
            {
                cin >> n;
                int nums[n];
                for (int j = 0; j < n; j++)
                {
                    cin >> nums[j];
                    nums[j] -= 1;
                }
                sort(nums, nums + n);
                if (s == "DR")
                {
                    for (int j = 0; j < n; j++)
                    {
                        gd.erase(gd.begin() + nums[j] - j);
                    }
                    row -= n;
                }
                else if (s == "DC")
                {
                    for (int j = 0; j < n; j++)
                    {
                        for (int k = 0; k < row; k++)
                        {
                            gd[k].erase(gd[k].begin() + nums[j] - j);
                        }
                    }
                    col -= n;
                }
                else if (s == "IR")
                {
                    for (int j = 0; j < n; j++)
                    {
                        gd.insert(gd.begin() + nums[j] + j, vector<int>(col, -1));
                    }
                    row += n;
                }
                else if (s == "IC")
                {
                    for (int j = 0; j < n; j++)
                    {
                        for (int k = 0; k < row; k++)
                        {
                            gd[k].insert(gd[k].begin() + nums[j] + j, -1);
                        }
                    }
                    col += n;
                }
            }
        }
        cin >> n;
        cout << "Spreadsheet #" << ++counter << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> r1 >> c1;
            r1 -= 1;
            c1 -= 1;
            bool fg = false;
            for (int j = 0; j < row; j++)
            {
                for (int k = 0; k < col; k++)
                {
                    if (gd[j][k] == r1 * org_col + c1)
                    {
                        fg = true;
                        cout << "Cell data in (" << r1 << "," << c1 << ") moved to (" << j + 1 << "," << k + 1 << ")" << endl;
                        break;
                    }
                }
                if (fg)
                    break;
            }
            if (!fg)
                cout << "Cell data in (" << r1 << "," << c1 << ") GONE" << endl;
        }
        cin >> r1 >> c1;
        if (r1 == 0 && c1 == 0)
            break;
    }
    return 0;
}