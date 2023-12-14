#include<iostream>
#include<map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    string s;
    while(getline(cin,s)){
        map<char,int>mp;
        for(const char&it:s){
            mp[it]++;
        }
        for(auto it:mp){
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
    return 0;
}