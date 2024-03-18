#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n,a,b;
    while(cin>>n){
        while(n--){
            string res="impossible";
            cin>>a>>b;
            //依題目：a 必大於 b 且相加是偶數
            if(a>=b&&!((a+b)&1)){
                res=to_string((a+b)/2)+" "+to_string((a-b)/2);
            }
            cout<<res<<endl;
        }
    }
    return 0;
}