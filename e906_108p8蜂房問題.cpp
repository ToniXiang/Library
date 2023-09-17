//	AC (3ms, 364KB)
#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n,n1;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>n1;
            cout<<n1+1<<endl;
        }
    }
    return 0;
}