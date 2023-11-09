#include<iostream>
#include<unordered_set>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n,cnt=1;
    while(cin>>n){
        int num[n];
        for(int i=0;i<n;i++){
            cin>>num[i];
        }
        unordered_set<int>st;
        string res="a B2-Sequence.";
        for(int i=n-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                int combine=num[i]+num[j];
                if(st.count(combine)){
                    res="not a B2-Sequence.";
                    i=-1;
                    break;
                }
                else{
                    st.insert(combine);
                }
            }
        }
        cout<<"Case #"<<cnt++<<": It is "<<res<<endl;
    }
    return 0;
}