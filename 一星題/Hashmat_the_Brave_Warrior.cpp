#include<iostream>
#include<math.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int a,b;
    while(cin>>a>>b){
        cout<<abs(a-b)<<endl;
    }
    return 0;
}