#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    vector<string>v;
    string s;
    int n=0;
    while(getline(cin,s)&&s!=""){
        v.push_back(s);
        n=max((int)s.size(),n);
    }
    for(int i=0;i<n;i++){
        for(int j=v.size()-1;j>=0;j--){
            cout<<(i<v[j].size()?v[j][i]:' ');
        }
        cout<<"\n";
    }
    return 0;
}