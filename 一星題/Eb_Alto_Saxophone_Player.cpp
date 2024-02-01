#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    unordered_map<char, vector<int>> mp;
    mp['c'] = {0,0,1,1,1,0,0,1,1,1,1};
    mp['d'] = {0,0,1,1,1,0,0,1,1,1,0};
    mp['e'] = {0,0,1,1,1,0,0,1,1,0,0};
    mp['f'] = {0,0,1,1,1,0,0,1,0,0,0};
    mp['g'] = {0,0,1,1,1,0,0,0,0,0,0};
    mp['a'] = {0,0,1,1,0,0,0,0,0,0,0};
    mp['b'] = {0,0,1,0,0,0,0,0,0,0,0};
    mp['C'] = {0,0,0,1,0,0,0,0,0,0,0};
    mp['D'] = {0,1,1,1,1,0,0,1,1,1,0};
    mp['E'] = {0,1,1,1,1,0,0,1,1,0,0};
    mp['F'] = {0,1,1,1,1,0,0,1,0,0,0};
    mp['G'] = {0,1,1,1,1,0,0,0,0,0,0};
    mp['A'] = {0,1,1,1,0,0,0,0,0,0,0};
    mp['B'] = {0,1,1,0,0,0,0,0,0,0,0};
    int n;
    cin >> n;
    while(n--){
        //uva 10415
        string s;
        cin >> s;
        int finger[11];
        for(int i=0;i<=10;i++) finger[i] = mp[s[0]][i];
        for(int i=1;i<s.size();i++){
            for(int j=1;j<=10;j++){
                if(mp[s[i]][j]&&!(mp[s[i-1]][j])){
                    finger[j]++;
                }
            }
        }
        for(int i=1;i<=10;i++){
            cout << finger[i] << " ";
        }
        cout << endl;
    }
    return 0;
}