#include<iostream>
#include<unordered_map>
using namespace std;
typedef long long ll;
unordered_map<ll,string>mp={{14,"kuti"},{12,"lakh"},{10,"hajar"},
{9,"shata"},{7,"kuti"},{5,"lakh"},{3,"hajar"},{2,"shata"}};
int main() {
    ios_base::sync_with_stdio(false);
    string s;
    int cnt=1;
    while(cin>>s){
        string base="",res="",buf="";
        for(int i=0;i<s.size();i++){
            if(mp.find(i)!=mp.end()){
                res=" "+buf+" "+base+res;
                buf="";
                base=mp[i];
            }
            buf=s[s.size()-i-1]+buf;
        }
        if(buf!="")res=" "+buf+" "+base+res;
        cout<<to_string(cnt++)+"."+res<<endl;
    }
    return 0;
}