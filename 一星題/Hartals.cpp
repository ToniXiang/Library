#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n,n1,n2,day;
    cin>>n;
    while(n--){
        cin>>n1>>n2;
        bool fg[n1+1]={false};
        while(n2--){
            cin>>day;
            for(int i=day;i<=n1;i+=day){
                fg[i]=true;
            }
        }
        int res=0;
        for(int i=1;i<=n1;i++){
            if((i%7)==0||(i%7)==6)continue;
            if(fg[i])res++;
        }
        cout<<res<<endl;
    }
    return 0;
}