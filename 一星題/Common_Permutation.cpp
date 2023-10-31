#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    string s,s1;
    while(cin>>s>>s1){
        unordered_map<char,int>mp,mp1;
        for(const char&it:s){
            mp[it]++;
        }
        for(const char&it:s1){
            mp1[it]++;
        }
        vector<pair<char,int>>v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[](const auto&a,const auto&b){return a.second<b.second;});
        string res="";
        for(const auto&it:v){
            string buf(min(it.second,mp1[it.first]),it.first);
            res+=buf;
        }
        cout<<res<<endl;
    }
    return 0;
}