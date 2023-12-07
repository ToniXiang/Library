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
        double total_x=f(a)*2+f(b)+f(c);
        double total_y=s(a)*2+s(b)+s(c);
        double res_x=total_x-3*f(a);
        double res_y=total_y-3*s(a);
        cout<<fixed<<setprecision(3)<<res_x<<" "<<res_y<<endl;
    }
    return 0;
}
/*
    這些公式是用來計算平行四邊形的第四個點的座標。
    在平行四邊形中，兩個點的向量和等於另兩個點的向量和。
    公式一：不是重複的點(b)+另一個不是重複的點(c)=重複的點(a)+要求的點(res)
    公式二：不是重複的點(b)+另一個不是重複的點(c)+[重複的點(a)*2]=重複的點(a)+要求的點(res)+[重複的點(a)*2]
    公式三(使用)：要求的點=2*重複的點(a)+不是重複的點(b)+另一個不是重複的點(c)-3*重複的點(a)
*/