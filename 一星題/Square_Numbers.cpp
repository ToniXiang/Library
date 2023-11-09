#include<iostream>
#include<math.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int a,b;
    while(cin>>a>>b){
        if(a==0||b==0)break;
        int a_sq=sqrt(a);
        int a_sq_pow=pow(a_sq,2);
        int res=0;
        for(int i=a_sq;i*i<=b;i++){
            res++;
            //cout<<i*i<<endl;
        }
        cout<<res<<endl;
    }
    return 0;
}