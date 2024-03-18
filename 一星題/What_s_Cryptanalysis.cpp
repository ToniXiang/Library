#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<char,int> pci;
bool cmp(const pci&a,const pci& b){
    if(a.second>b.second)return true;
    else if(a.second<b.second)return false;
    return a.first<b.first;
}
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
        vector<pci>res(mp.begin(),mp.end());
        sort(res.begin(),res.end(),cmp);
        for(const auto&it:res){
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
    return 0;
}
// 計算每個字母出現的次數，並且按照出現次數由大到小排序，如果次數相同則按照字母順序排序