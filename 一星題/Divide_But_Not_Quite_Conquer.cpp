#include<iostream>
#include<sstream>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    ll a,b;
    while(cin>>a>>b){
        if(a==0||b==0){
            cout<<"Boring!"<<endl;
            continue;
        }
        stringstream ss;
        ss<<to_string(a)+" ";
        while(a>1){
            if(a%b==0){
                a/=b;
                ss<<to_string(a)+" ";
            }
            else{
                break;
            }
        }
        cout<<(a==1?ss.str():"Boring!")<<endl;
    }
    return 0;
}