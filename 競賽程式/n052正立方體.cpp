// 	AC (2ms, 344KB)
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
string s,buf;
int geti(){
    getline(cin,s);
    auto newend=remove(s.begin(),s.end(),' ');
    s.erase(newend,s.end());
    return atoi(s.c_str());
}
bool check(int val1,int val2){
    if(val1==1410||val1==141)return true;
    if(val2==1410||val2==141)return true;
    if((val1==1311||val1==1221||val1==1212)&&(val2==132||val2==1320||val2==231||val2==2310))return true;
    if((val2==1311||val2==1221||val2==1212)&&(val1==132||val1==1320||val1==231||val1==2310))return true;
    if(val1==1221&&(val2==2220||val2==222))return true;
    if(val2==1221&&(val1==2220||val1==222))return true;
    return false;
}
vector<int>pow_E={1000,100,10,1};
int main() {
    ios_base::sync_with_stdio(false);
    int n=geti();
    while(n--){
        vector<vector<bool>>mp(4,vector<bool>(4,false));
        getline(cin,s);
        stringstream ss(s);
        while(getline(ss,buf,' ')){
            int val=atoi(buf.c_str())-1;
            mp[val/4][val%4]=true;
        }
        // 1,4,1型 2,3,1型 2,2,2型 判斷
        int val1=0,val2=0,val3=0,val4=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                val1+=(mp[i][j])?pow_E[i]:0;
                val3+=(mp[i][j])?pow_E[3-i]:0;
                val2+=(mp[j][i])?pow_E[i]:0;
                val4+=(mp[j][i])?pow_E[3-i]:0;
            }
        }
        cout<<(check(val1,val2)||check(val3,val4)?"yes":"no")<<endl;
    }
    return 0;
}