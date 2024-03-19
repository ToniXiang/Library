#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int a, b, x, y;
    char z;
    string s;
    cin >> a >> b;
    vector<vector<int>> mp(a+1, vector<int>(b+1, 0));
    string dir = "ESWN";
    map<char, int> moved = {{'E', 1},{'W', -1},{'N', 0},{'S', 0}};
    map<char, int> moved2 = {{'N', 1},{'S', -1},{'E', 0},{'W', 0}};
    while(cin >> x >> y >> z >> s){
        bool fg = true;
        for(char command : s){
            if(command == 'R')z = dir[(dir.find(z)+1)%4];
            else if(command == 'L')z = dir[(dir.find(z)+3)%4];
            else if(command == 'F')x=x+moved[z],y=y+moved2[z];
            if(x < 0 || y < 0 || x > a || y > b){
                x=x-moved[z],y=y-moved2[z];
                if(mp[x][y] == 1) continue;
                mp[x][y] = 1;
                fg = false;
                break;
            }
        }
        cout << x << " " << y << " " << z <<(!fg?" LOST\n":"\n");
    }
    return 0;
}