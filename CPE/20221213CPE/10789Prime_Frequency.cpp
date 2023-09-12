#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;
bool check(int v){
    if(v==1)return false;
    if(v==2)return true;
    if(v==3)return true;
    int m=v%6;
    if(m!=1&&m!=5)return false;
    int sq=(int)sqrt(v);
    for(int i=5;i<=sq;i+=6){
        if(v%i==0||v%(i+2)==0)return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        map<char,int>mp;
        vector<pair<char,int>>v;
        cin>>s;
        for(const char ch:s){
            mp[ch]++;
        }
        for(const auto item:mp){
            if(check(item.second))v.push_back({item.first,item.second});
        }
        sort(v.begin(),v.end(),[](auto a,auto b){return a.first>a.first;});
        cout<<"Case "<<i+1<<":";
        for(const auto item:v){
            cout<<item.first;
        }
        if(v.size()==0)cout<<"empty";
        cout<<"\r\n";
    }
    return 0;
}