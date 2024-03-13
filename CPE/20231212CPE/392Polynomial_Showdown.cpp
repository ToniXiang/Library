#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int arr[9];
    while (cin >> arr[0])
    {
        for (int i = 1; i < 9; i++)
        {
            cin >> arr[i];
        }
        int rd = 8;
        bool fg = false;
        for (int data : arr)
        {
            if (data == 0)
            {
                rd--;
                continue;
            }
            int positive = abs(data);
            if (!fg)
            {
                cout << (data > 0 ? "" : "-");
                cout << (positive != 1 ? to_string(positive):"");
                if (rd == 1)
                    cout << "x";
                else if (rd != 0)
                    cout << "x^" << to_string(rd);
            }
            else
            {
                cout << (data > 0 ? " + " : " - ");
                if (rd == 0)
                    cout << to_string(positive);
                else if (rd == 1)
                    cout << (positive != 1 ? to_string(positive) : "") << "x";
                else
                    cout << (positive != 1 ? to_string(positive) : "") << "x^" << to_string(rd);
            }
            if (positive != 0)
                fg = true;
            rd--;
        }
        if(!fg)
            cout << "0";
        cout << endl;
    }
    return 0;
}