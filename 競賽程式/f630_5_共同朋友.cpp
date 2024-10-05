//  AC (0.4s, 1.1MB)
#include<iostream>
#include<bitset>
#include<vector>
using namespace std;
constexpr int N=2501;
int main() {
    ios_base::sync_with_stdio(false);
    int n,di,fij;
    while(cin>>n){
        vector<bitset<N>>vbs(n+1);
        for(int i=0;i<n;++i){
            cin>>di;
            for(int j=0;j<di;++j){
                cin>>fij;
                vbs[i].set(fij,1);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                bitset<N>tmp=vbs[i]&vbs[j];
                if(tmp.any())ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
// bitset 降低時間 + 空間，不用每個值存一個陣列和多餘的迴圈判斷