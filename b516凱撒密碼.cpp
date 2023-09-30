#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    string s;
    cin>>n>>ws;
    char ch;
    while(n--){
        string res="";
        cin>>s;
        for(const char&it:s){
            res+=(char)((it-'A'+3)%26+'A');
        }
        cout<<res<<"\n";
    }
    return 0;
}