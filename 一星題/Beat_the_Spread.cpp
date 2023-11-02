#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    double a,b;
    while(cin>>n){
        while(n--){
            string res="impossible";
            cin>>a>>b;
            if(a>b){
                //x+y=a
                //x-y=b
                //2x=a+b
                //y=a-x
                double x=(a+b)/2;
                if(x-(int)x==0){
                    int y=a-x;
                    res=to_string((int)x)+" "+to_string((int)y);
                }
            }
            cout<<res<<endl;
        }
    }
    return 0;
}