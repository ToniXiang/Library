#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    int n,n1;
    while(cin>>n){
        while(n--){
            cin>>n1;
            int num[n1];
            for(int i=0;i<n1;i++){
                cin>>num[i];
            }
            sort(num,num+n1);
            ll res=0;
            for(int i=0;i<n1;i++){
                res+=abs(num[i]-num[(n1-1)>>1]);
            }
            cout<<res<<endl;
        }
    }
    return 0;
}
// 計算中位數
// 輸入：
// n
// n1 num[0]、num[1]...num[n1-1]
// ...