#include<iostream>
#include<bitset>
using namespace std;
string decimalToBinary(int decimal,int length){
    bitset<32>bit(decimal);
    string s=bit.to_string();
    int aim=-1;
    for(int i=0;i<32;i++){
        if(s[i]=='1'){
            aim=i;
            break;
        }
    }
    return s.substr(aim);
}
int main() {
    ios_base::sync_with_stdio(false);
    int n_org,a;
    while (cin>>n_org)
    {
        if(n_org==0)break;
        int res=0,n=n_org;
        while (n!=0)
        {
            res++;
            n&=(n-1);
        }
        cout<<"The parity of "<<decimalToBinary(n_org,res)<<" is "<<res<<" (mod 2)."<<endl;
    }
    return 0;
}