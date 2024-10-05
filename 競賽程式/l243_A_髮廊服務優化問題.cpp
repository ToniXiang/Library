//  AC (2ms, 364KB)
#include<iostream>
#include<set>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n,ti;
    while(cin>>n){
        multiset<int>ms;
        for(int i=0;i<n;++i){
            cin>>ti;
            ms.insert(ti);
        }
        auto cur=ms.begin();
        int res=0,total=0;
        while(cur!=ms.end()){
            total+=*cur;
            res+=total;
            cur=std::next(cur);
        }
        cout<<res<<endl;
    }
    return 0;
}
//  排序 + 前綴和