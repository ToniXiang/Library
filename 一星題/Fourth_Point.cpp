#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
using namespace std;
typedef pair<double,double> pdd;
int main() {
    ios_base::sync_with_stdio(false);
    double a,b,c,d,e,f,g,h;
    while(cin>>a>>b>>c>>d>>e>>f>>g>>h){
        vector<pdd>v{{a,b},{c,d},{e,f},{g,h}};
        set<pdd>st;
        pdd target;
        for(const pdd&it:v){
            if(st.count(it)){
                target=it;
                break;
            }
            st.insert(it);
        }
        pdd total={a+c+e+g,b+d+f+h};
        pdd res={total.first-3*target.first,total.second-3*target.second};
        cout<<fixed<<setprecision(3)<<res.first<<" "<<res.second<<endl;
    }
    return 0;
}
// 要求的點 = 所有點座標 - 3 * 重複的點