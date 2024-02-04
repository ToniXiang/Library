#include<iostream>
#include<string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // untie cin and cout
    int n, tmp, pos[7];
    string s;
    while(cin >> n && n != 0) {
        for(int i = 1; i <= 6; i++) pos[i] = i;
        while(n--) {
            cin >> s;
            if(s == "north") {
                tmp = pos[2];
                pos[2] = pos[1];//北轉
                pos[1] = pos[5];//北>底 底>南  南>頂  頂>北
                pos[5] = pos[6];//記：北 <-> 南
                pos[6] = tmp;
            } else if(s == "east") {
                tmp = pos[4];
                pos[4] = pos[1];//東轉
                pos[1] = pos[3];//東>底 底>西  西>頂  頂>東
                pos[3] = pos[6];//記：東 <-> 西
                pos[6] = tmp;
            } else if(s == "south") {
                tmp = pos[5];
                pos[5] = pos[1];//南轉
                pos[1] = pos[2];//南>底 底>北  北>頂  頂>南
                pos[2] = pos[6];//記：南 <-> 北
                pos[6] = tmp;
            } else if(s == "west") {
                tmp = pos[3];
                pos[3] = pos[1];//西轉
                pos[1] = pos[4];//西>底 底>東  東>頂  頂>西
                pos[4] = pos[6];//記：西 <-> 東
                pos[6] = tmp;
            }
        }
        cout << pos[1] << '\n';
    }
    return 0;
}