#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    while(cin>>n){
        if(n<=0)break;
        int res_bin=0;
        string res_s="";
        while(n>0){
            if((n&1)==1){
                res_bin++;
                res_s="1"+res_s;
            }
            else{
                res_s="0"+res_s;
            }
            n>>=1;
        }
        cout<<"The parity of "<<res_s<<" is "<<res_bin<<" (mod 2)."<<endl;
    }
    return 0;
}