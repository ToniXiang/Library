//	AC (3ms, 356KB)
#include<iostream>
#include<set>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    string s;
    while(cin>>s){
        int len=0,len_0=0,len_1=0;
        set<string>st_101;
        string buffer="";
        for(char it:s){
            if(it=='0')len_0++;
            if(it=='1')len_1++;
            buffer+=it;
            if(buffer.size()==3){
                st_101.insert(buffer);
                buffer=buffer.substr(1);
            }
            len++;
        }
        string res="";
        if(len!=len_0+len_1)res+="1 ";
        if(len<8||len>12)res+="2 ";
        if(len_0<2)res+="3 ";
        if(len_1<3)res+="4 ";
        if(!st_101.count("101"))res+="5 ";
        if(res!="")cout<<res<<endl;
        else cout<<"0"<<endl;
    }
    return 0;
}