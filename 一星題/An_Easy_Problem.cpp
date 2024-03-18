#include<iostream>
using namespace std;
typedef long long ll;
int cmap(char ch){
    if(ch>='a'&&ch<='z')return ch-'a'+36;
    else if(ch>='A'&&ch<='Z')return ch-'A'+10;
    else if(ch>='0'&&ch<='9')return ch-'0';
    else return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    string s;
    while(cin>>s){
        int base=0;
        ll sum=0;
        for(const char&it:s){
            const int val=cmap(it);
            sum+=val;
            base=max(base,val);
        }
        string res="such number is impossible!";
        for(int i=base;i<61;i++){
            if(sum%i==0){
                res=to_string(i+1);
                break;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
// 題目：給定一個 res 進制 s 保證可以被 (res-1) 整除，求最小的 res
// 【abc】是 (res - 1) 的倍數，則【a + b + c】也是(res -1)的倍數