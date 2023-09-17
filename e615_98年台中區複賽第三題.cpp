#include<iostream>
#include<unordered_map>
#include<string> 
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    string s;
    while(cin>>n){
        unordered_map<string,string>mp;
        while(cin>>s&&--n)
        {
            mp[s.substr(0, 3)]=s;
        }
        string aim="";
        string res="";
        aim=mp["色"];
        for(int i = 0; i < aim.size(); i += 3) {
            cout << aim.substr(i, 3);
        }
        cout<<endl;
    }
    return 0;
}