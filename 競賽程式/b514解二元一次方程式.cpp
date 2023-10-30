#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n,a,b,c,d,e,f;
    cin>>n>>ws;
    for(int i=0;i<n;i++){
        if(cin>>a>>b>>c>>d>>e>>f,f){
            int y = (a*f - d*c) / (a*e - b*d);
            int x = (b*f - e*c) / (b*d - a*e);
            cout<<x<<" "<<y<<endl;
        }
    }
    return 0;
}