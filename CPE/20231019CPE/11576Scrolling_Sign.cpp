#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n,a,b;
    string s;
    cin>>n;
    while(n--){
        cin>>a>>b;
        vector<string>v;
        v.resize(b);
        for(int i=0;i<b;i++){
            cin>>s;
            v.push_back(s);
        }
        int res=a*b;
        for(int i=0;i<b-1;i++){
            for(int j=0;j<a;j++){
                if(v[i].substr(j,a-j)==v[i+1].substr(0,a-j)){
                    res-=(a-j);
                    break;
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}