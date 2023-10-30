//AC (2ms, 324KB)
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    while(cin>>n){
        string arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n,[](string a,string b){return a+b>b+a;});
        for(int i=0;i<n;i++){
            cout<<arr[i];
        }
        cout<<"\n";
    }
    return 0;
}