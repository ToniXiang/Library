#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    string s;
    while(cin>>s){
        if(s=="0")break;
        int odd=0,even=0;
        for(int i=s.size()-1,j=1;i>=0;i--,j++){
            if((j&1)==1)odd+=s[i]-'0';
            else even+=s[i]-'0';
        }
        cout<<s<<" is "<<((odd-even)%11==0?"":"not ")<<"a multiple of 11."<<endl;
    }
    return 0;
}
// 輸入數字字串，判斷奇數位和偶數位差是否為 11 的倍數
// 如何判斷： odd 與 even 分別計算總和，相差可被 11 整除，則該數字為 11 的倍數