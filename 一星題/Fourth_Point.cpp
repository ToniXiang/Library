#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;
typedef pair<double,int> pdi;
bool tmp(const pdi&a,const pdi& b){
    return a.second>b.second;
}
int main() {
    ios_base::sync_with_stdio(false);
    double x,y;
    while(cin>>x>>y){
        unordered_map<double,int>mp_x;
        unordered_map<double,int>mp_y;
        mp_x[x]++;
        mp_y[y]++;
        for(int i=1;i<4;i++){
            cin>>x>>y;
            mp_x[x]++;
            mp_y[y]++;
        }
        vector<pdi>res_x(mp_x.begin(),mp_x.end());
        sort(res_x.begin(),res_x.end(),tmp); 
        vector<pdi>res_y(mp_y.begin(),mp_y.end());
        sort(res_y.begin(),res_y.end(),tmp);
        cout<<fixed<<setprecision(3)<<res_x[0].first<<" "<<res_y[0].first<<endl;
    }
    return 0;
}