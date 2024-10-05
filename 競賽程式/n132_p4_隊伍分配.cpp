//  NA (score:30%) 嘗試貪心...只有局部最佳解
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    int n,k;
    ll ni;
    while(cin>>n>>k){
        vector<ll>v(n);
        for(int i=0;i<n;++i){
            cin>>v[i];
        }
        int kk=n/k;
        ll res=1;
        int left=0,right=n-1;
        vector<ll>final={0};
        while(left<=right){
            ll total=0;
            for(int i=0;i<kk/2;i++){
                total+=v[left++];
                total+=v[right--];
            }
            if (kk % 2 == 1) {
                if (left == right) {
                    total+=v[left++];
                } else {
                    if (abs(final.back()-(total+v[left])) > abs(final.back()-(total+v[right]))) {
                        total+=v[left++];
                    } else {
                        total+=v[right--];
                    }
                }
            }
            res*=total;
            final.push_back(total);
        }
        cout<<res<<endl;
        //6 2
        //1 2 3 4 5 6
        //(1+2+6)=9 差最小
        //(3+4)=7 63
        //
        //1+5+6=12
        //2+3+4=9 108
        //
        //10 2
        //1 2 3 4 5 6 7 8 9 10
        //1+2+9+10+3=25
        //4+5+8+7+6=30 30*25=750
    }
    return 0;
}