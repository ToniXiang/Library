#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    string s;
    while(cin>>n){
        cin.ignore();
        unordered_map<char,int>mp;
        while(n--){
            getline(cin,s);
            for(const auto&it:s){
                if(it>='A'&&it<='Z')mp[it]++;
                else if(it>='a'&&it<='z')mp[it-'a'+'A']++;
            }
        }
        vector<pair<char,int>>res(mp.begin(),mp.end());
        sort(res.begin(),res.end(),[](const auto&a,const auto&b){return a.second>b.second;});
        for(const auto&it:res){
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
    return 0;
}