#include<iostream>
#include<sstream>
#include<map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    string s,buf;
    while(cin>>n){
        map<string,int>mp;
        cin.ignore();
        while(n--){
            getline(cin,s);
            stringstream ss(s);
            ss>>buf;
            mp[buf]++;
        }
        for(auto&it:mp){
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
    return 0;
}
//程式碼遍歷 map 並將每個單詞及其頻率打印到標準輸出