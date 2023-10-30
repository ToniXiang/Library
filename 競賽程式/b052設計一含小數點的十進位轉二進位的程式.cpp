//AC (2ms, 324KB)
#include<iostream>
#include<math.h>
#include<bitset>
using namespace std;
string decimalToBinary(int decimal){
    string res="";
    int m=1<<8;
    bool fg=false;
    for(int i=0;i<9;i++){
        if(decimal>=m){
            decimal-=m;
            res+="1";
            fg=true;
        }
        else if(fg){
            res+="0";
        }
        m>>=1;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    double n;
    while(cin>>n){
        double f=n-(int)n;
        if(f<0){
            cout<<decimalToBinary((int)n)<<endl;
        }
        else{
            string rd=".";
            while(f!=0){
                f*=2;
                if(f>=1)f-=1,rd+="1";
                else rd+="0";
            }
            cout<<decimalToBinary((int)n)<<rd<<endl;
        }
    }
    return 0;
}