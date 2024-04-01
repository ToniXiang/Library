#include<iostream>
#include<sstream>
#include<vector>
#include<iomanip>
using namespace std;
typedef long double llb;
int main() {
    ios_base::sync_with_stdio(false);
    string s,buf;
    while(cin>>s){
        s+=",";
        buf="";
        vector<int> v;
        for(const char&it:s){
            if(it==','||it==';'){
                v.push_back(atoi(buf.c_str()));
                buf="";
            }
            else{
                buf+=it;
            }
        }
        llb result=v.back();
        for (int i=v.size()-2;i>=0;i--) {
            result=(llb)v[i]+1.0/result;
            // cout<<fixed<<setprecision(15)<<result<<endl;
        }
        stringstream ss;
        ss<<fixed<<setprecision(15)<<result;
        cout<<ss.str()<<endl;
    }
    return 0;
}