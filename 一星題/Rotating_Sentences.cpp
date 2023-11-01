#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    string a,b;
    while(true){
        getline(cin,a);
        getline(cin,b);
        int len=max(a.size(),b.size());
        for(int i=0;i<len;i++){
            cout<<(i<b.size()?b[i]:' ')<<(i<a.size()?a[i]:' ')<<endl;
        }
    }
    return 0;
}