#include<iostream>
#include<vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    vector<bool>isprime(65536, true);
    isprime[0]=isprime[1]=false;
    for(int j=2;j*j<65536;j++){
        if(isprime[j]){
            for(int k=j*j;k<65536;k+=j){
                isprime[k]=false;
            }
        }
    }
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        cout<<(isprime[x]?"Y":"N")<<endl;
    }
    return 0;
}