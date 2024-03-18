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
            cout<<v[i]<<" ";
            if(v[i]+1!=v[i+1]){
                fg=true;
                break;
            }
        }
        cout<<(fg?"Not jolly":"Jolly")<<endl;
    }
    return 0;
}
// 輸入一個數列，判斷是否為 Jolly 數列
// Jolly 數列定義為：數列中相鄰兩數的差的絕對值為 1~n-1
// input：n v0、v1、v2、...、vn-1