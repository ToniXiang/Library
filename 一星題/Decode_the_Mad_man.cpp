#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    //建表 依題目：解密為字串在鍵盤上左移兩位
    string table="`1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./";
    string s,buf;
    while(getline(cin,s)){
        string res="";
        for(char it:s){
            if(it>='A'&&it<='Z')it=tolower(it);
            if(it==' '){
                res+=" ";
                continue;
            }
            for(int i=0;i<table.size();i++){
                if(it==table[i]){
                    res+=table[i-2];
                    break;
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}