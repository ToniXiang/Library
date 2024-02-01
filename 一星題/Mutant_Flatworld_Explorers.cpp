#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int a, b, x, y;
    char z;
    string s;
    cin >> a >> b;
    vector<vector<int>> mp(a+1, vector<int>(b+1, 0));
    while(cin >> x >> y >> z >> s){
        bool ok = true;
        for(char command : s){
            if(command == 'R'){
                if(z == 'E') z = 'S';
                else if(z == 'S') z = 'W';
                else if(z == 'W') z = 'N';
                else if(z == 'N') z = 'E';
            } else if(command == 'L'){
                if(z == 'E') z = 'N';
                else if(z == 'S') z = 'E';
                else if(z == 'W') z = 'S';
                else if(z == 'N') z = 'W';
            } else if(command == 'F'){
                if(z == 'E') x++;
                else if(z == 'S') y--;
                else if(z == 'W') x--;
                else if(z == 'N') y++;
            }
            if(x < 0 || y < 0 || x > a || y > b){
                if(z == 'E') x--;
                else if(z == 'S') y++;
                else if(z == 'W') x++;
                else if(z == 'N') y--;
                if(mp[x][y] == 1) continue;
                mp[x][y] = 1;
                ok = false;
                break;
            }
        }
        cout << x << " " << y << " " << z;
        if(!ok) cout << " LOST";
        cout << endl;
    }
    return 0;
}