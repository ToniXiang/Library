#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    while(cin>>n){
        int head,tail;
        cin>>head;
        vector<int>v;       
        for(int i=1;i<n;i++){
            cin>>tail;
            v.push_back(abs(head-tail));
            head=tail;
        }
        sort(v.begin(),v.end());
        bool fg=false;
        for(int i=0;i<v.size()-1;i++){
            if(v[i]+1!=v[i+1]){
                fg=true;
                break;
            }
        }
        cout<<(fg?"Not jolly":"Jolly")<<endl;
    }
    return 0;
}