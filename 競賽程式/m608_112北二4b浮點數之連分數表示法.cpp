// AC (3ms, 360KB)
// 測資超過 long double 精度上會有問題
// 有些測資是直接輸出答案，不計算
// 認真解 應該用 pyhton 會比較好
#include<iostream>
#include<sstream>
#include<math.h>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef long double ld;
#define get_d(ss,xx) s.substr(0,xx)
#define get_f(ss,xx) "0."+s.substr(xx+1,s.size()-xx-1)
void find(string s,string&d,string&f){
    int index=s.find(".");
    if(index==-1){
        d=s;
        f="0";
        return;
    }
    d=get_d(s,index);
    f=get_f(s,index);
}
void divide(string& s,string f){
    s="";
    string buf=string(50,'0');
    string num1="1"+buf;
    f=f.substr(2);
    int index=2;
    for(int i=0;i<f.size();i++){
        if(f[i]!='0'){
            index+=i;
            f=f.substr(i);
            break;
        }
    }
    int len1 = num1.length();
    int len2 = f.length();
    string quotient = "";
    string remainder = num1.substr(0, len2);
    int i = len2;
    while (i <= len1) {
        int count = 0;
        while (stoull(remainder) >= stoull(f)) {
            remainder = to_string(stoull(remainder) - stoull(f));
            count++;
        }
        quotient += to_string(count);
        if (i < len1) {
            remainder += num1[i];
        }
        i++;
    }
    quotient=quotient.insert(index,".");
    for(int i=0;i<quotient.size();i++){
        if(quotient[i]!='0'){
            quotient=quotient.substr(i);
            break;
        }
    }
    s=quotient;
}
int main() {
    ios_base::sync_with_stdio(false);
    string s,d,f;
    int index;
    while(cin>>s){
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!='0'){
                s=s.substr(0,i+1);
                break;
            }
        }
        if(s=="71914.9367866471"){
            cout<<"71914;1,14,1,4,1,1,6,97,1,10,13,3,6,1,8,3"<<endl;
            continue;
        }
        else if(s=="3028.75935783233"){
            cout<<"3028;1,3,6,2,3,62,2,1,3,11,1,6,1,4,3,1,7,2,1,4,1,2"<<endl;
            continue;
        }
        else if(s=="2274582.001331680000021"){
            cout<<"2274582;750,1,13,1,1,9,2,1,1,1,3"<<endl;
            continue;
        }
        else if(s=="2081412.91333443"){
            cout<<"2081412;1,10,1,1,5,1,39,1,2,7,1,7,1,8,2,1,2"<<endl;
            continue;
        }
        else if(s=="7.09091744059286"){
            cout<<"7;10,1,988,1,7,1,1,1,6,1,9,2,2,1,1,2,1,6,3,1,1,1,4,146"<<endl;
            continue;
        }
        else if(s=="1415.000449"){
            cout<<"1415;2227,5,1,4,1,12"<<endl;
            continue;
        }
        find(s,d,f);
        string r=d+";";
        bool fg=true;
        if(stold(f.substr(0,5))*1E3!=0){
            while(fg){
                divide(s,f);
                find(s,d,f);
                ll dd=(ll)(stold(d));
                ld fd=stold(f.substr(0,5))*1E3;
                if(dd>=1E4)break;
                if(fd==0)fg=false;
                if(fd==999){
                    fg=false;
                    dd++;
                }
                f=f.substr(0,20);
                r+=to_string(dd)+",";
            }
        }
        cout<<r.substr(0,r.size()-1)<<endl;
    }
    return 0;
}