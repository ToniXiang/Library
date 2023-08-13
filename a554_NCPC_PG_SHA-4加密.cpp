#include<iostream>
#include<iomanip>
using namespace std;
typedef unsigned int ui;
#define pad(val) cout<<hex<<setw(8)<<setfill('0')<<val<<" ";
int main() {
    ios_base::sync_with_stdio(false);
    ui h[5]={0xdead,0xcafe,0xbeef,0x3399,0x7788};
    int n;
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        ui w[5]={0};
        for(int j=0;j<5;j++){
            w[j]=(s[j]-' ');
        }
        ui a=h[0],b=h[1],c=h[2],d=h[3],e=h[4],temp;
        for(int j=0;j<5;j++){
            cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;
            ui f=b+c,k=0x5a82;
            temp=4*a+f+e+k+w[j];
            e=d;d=c;c=b<<3;b=a;a=temp;
        }
        a+=h[0];b+=h[1];c+=h[2];d+=h[3];e+=h[4];
        pad(a);pad(b);pad(c);pad(d);pad(e);
        cout<<"\n";
    }
    return 0;
}
/*
4
5dogs
9cats
fade4
cafe8
*/