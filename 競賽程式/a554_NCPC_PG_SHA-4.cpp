#include<iostream>
using namespace std;
typedef unsigned int ui;
int main() {
    ios_base::sync_with_stdio(false);
    ui h[5]={0xdead,0xcafe,0xbeef,0x3399,0x7788};
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        ui w[5]={0};
        for(int j=0;j<5;j++){
            cin>>hex>>w[j];
        }
        string result="";
        ui k=0x5a82;
        ui a=w[0]-h[0],b=w[1]-h[1],c=w[2]-h[2],d=w[3]-h[3],e=w[4]-h[4],temp;
        for(int j=0;j<5;j++){
            temp=a;a=b;b=c>>3;c=d;d=e;e=h[j];
            if(j<=1)e<<=3;
            ui f=b+c;
            w[4-j]=temp-(4*a+f+e+k);
            result=(char)(w[4-j]+' ')+result;
        }   
        cout<<result<<endl;
    }
    return 0;
}