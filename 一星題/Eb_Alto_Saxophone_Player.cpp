#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<char, ll> mp;
    mp['c'] = 0b0111001111;
    mp['d'] = 0b0111001110;
    mp['e'] = 0b0111001100;
    mp['f'] = 0b0111001000;
    mp['g'] = 0b0111000000;
    mp['a'] = 0b0110000000;
    mp['b'] = 0b0100000000;
    mp['C'] = 0b0010000000;
    mp['D'] = 0b1111001110;
    mp['E'] = 0b1111001100;
    mp['F'] = 0b1111001000;
    mp['G'] = 0b1111000000;
    mp['A'] = 0b1110000000;
    mp['B'] = 0b1100000000;
    int n;
    string s;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        getline(cin, s);
        ll prev = mp[s[0]], finger[10] = {0};
        for(int i=0;i<10;i++){
            finger[i]=prev&0b1;
            prev >>= 1;
        }
        prev=mp[s[0]];
        for(int i=1;i<s.size();i++){
            ll curr = mp[s[i]];
            for(int j=0;j<10;j++){
                if (!(prev & 0b1) && (curr & 0b1))
                {
                    finger[j]++;
                }
                curr >>= 1;
                prev >>= 1;
            }
            prev = mp[s[i]];
        }
        for (int i = 0; i < 10; i++)
        {
            cout << finger[9-i] << " ";
        }
        cout << '\n';
    }
    return 0;
}