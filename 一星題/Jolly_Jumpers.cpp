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
//這題的思路是，先把輸入的數據存到vector中，然後再進行操作
//操作的時候，先把vector排序，然後再判斷是否是jolly jumper
//如果不是，就輸出Not jolly，否則輸出Jolly