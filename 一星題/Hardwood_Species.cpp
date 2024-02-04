#include<iostream>
#include<map>
#include<iomanip>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n>>ws;
    while(n--){
        map<string,int> m;
        string s;
        int cnt=0;
        while(getline(cin,s)&&s!=""){
            m[s]++;
            cnt++;
        }
        for(const auto i:m){
            cout<<i.first<<" "<<fixed<<setprecision(4)<<i.second*100.0/cnt<<endl;
        }
        if(n) cout<<endl;
    }
    return 0;
}