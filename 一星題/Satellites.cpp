#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    double s,a,r = 6440.0;
    string unit;
    while(cin>>s>>a>>unit){
        if(unit=="min")a/=60;
        if(a>180)a=360-a;
        double are=2.0*M_PI*(s+r)*a/360.0;
        double chord=2.0*(r+s)*cos((90.0-a/2.0)/180.0*M_PI);
        cout<<fixed<<setprecision(6)<<are<<" "<<chord<<endl;
    }
    return 0;
}