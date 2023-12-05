#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;
typedef pair<double,double> pdd;
typedef pair<pair<double,double>,int> ppddi;
#define f(xx) xx.first
#define s(yy) yy.second
#define r(zz) static_cast<int>(zz * 1E3)/1E3
int main() {
    ios_base::sync_with_stdio(false);
    double x,y;
    while(cin>>x>>y){
        map<pdd,int>mp;
        mp[make_pair(x,y)]++;
        for(int i=1;i<4;i++){
            cin>>x>>y;
            mp[make_pair(x,y)]++;
        }
        vector<ppddi>v_sort(mp.begin(),mp.end());
        sort(v_sort.begin(),v_sort.end(),[](const ppddi& a,const ppddi& b){return s(a)>s(b);});
        pdd a=f(v_sort[0]),b=f(v_sort[1]),c=f(v_sort[2]);
        float center_x = (f(b) + f(c)) / 2.0f;
		float center_y = (s(b) + s(c)) / 2.0f;
        float res_x=f(a) + (center_x - f(a)) * 2.0f;
        float res_y=s(a) + (center_y - s(a)) * 2.0f;
        cout<<fixed<<setprecision(3)<<r(res_x)<<" "<<r(res_y)<<endl;
    }
    return 0;
}