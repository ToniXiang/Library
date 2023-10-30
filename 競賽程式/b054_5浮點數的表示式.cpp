#include<iostream>
#include<bitset>
#include<math.h>
using namespace std;
string decimalToBinary(int decimal,bool fg){
   bitset<8>bit(decimal);
   string r=bit.to_string();
   string buffer(8-r.size(),'0');
   string res=buffer+r;
   return (fg?res.substr(1):res);
}
char conv16(int i){
    if(i<10)return (char)(i+'0');
    return (char)('A'+i-10);
}
string binaryToHex(string binary) {
    string res="";
    int data=0;
    for(int i=7;i>=0;i--){
        data+=(binary[i]-'0')*pow(2,4-i%4-1);
        if(i==0||i==4)res=conv16(data)+res,data=0;
    }
    return "<&H"+res+">";
}
int main() {
    ios_base::sync_with_stdio(false);
    double n;
    while(cin>>n){
        cout<<"Input a value: "<<n<<endl;
        cout<<"                 Exponent lst byte 2nd byte 3rd byte"<<endl;
        int bit_val=0;
        double n1=abs(n);
        if(n1>=1){
            while(n1>=1){
                bit_val++;
                n1/=2;
            }   
        }
        else{
            while (n1!=0)
            {
                if(n1*2>=1)break;
                bit_val++;
                n1*=2;
            }
        }
        string Exponent=(n-static_cast<int>(n)<=1.0E-7?"1"+decimalToBinary(bit_val,true):decimalToBinary((bit_val^127)+1,false));
        string res="";
        int power=(abs(n)<1?-bit_val:bit_val);
        double val=abs(n)/pow(2,power);
        while (val!=0)
        {
            val*=2;
            if(val>=1)res+="1",val-=1;
            else res+="0";
        }
        res=res.substr(0,24);
        string buffer(24-res.size(),'0');
        string point=res+buffer;
        string sq1=point.substr(1,7);
        string sq2=point.substr(8,8);
        string sq3=point.substr(16,8);
        cout<<"Memory Contents= "<<Exponent<<" "<<(n<0?"1":"0")<<sq1<<" "<<sq2<<" "<<sq3<<endl;
        cout<<"                 "<<binaryToHex(Exponent)<<"   "<<binaryToHex((n<0?"1":"0")+sq1)<<"   "<<binaryToHex(sq2)<<"   "<<binaryToHex(sq3)<<endl;
        cout<<"FLOATING POINT FORMAT => "<<(n<0?"-":"")<<"0."<<point<<" * 2 ^ "<<power<<endl;
        cout<<"Floating Point Value = "<<n<<endl;
        cout<<"================================================================="<<endl;
    }
    return 0;
}