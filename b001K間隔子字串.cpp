#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int k;
    string s;
    while(cin>>k>>s){
        int res=0;
        for(int i=0;i<s.size();i++){
            for(int j=i+k;j<s.size();j++){
                int len=j-i-k+1;
                if(s.substr(i,len)==s.substr(j+1,len))res++;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}