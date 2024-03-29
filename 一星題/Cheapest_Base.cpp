#include<iostream>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    int n,n1;
    ll a,b;
    int cost[36]={0};
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<"Case "<<i<<endl;
        for(int j=0;j<36;j++){
            cin>>cost[j];
        }
        cin>>n1;
        while(n1--){
            cin>>a;
            ll res=1E9;
            int rd[37]={0};
            for(int j=2;j<=36;j++){
                b=a;
                ll val=0;
                while(b>0){
                    val+=cost[b%j];
                    b/=j;
                }
                rd[j]=val;
                res=min(val,res);
            }
            cout<<"Cheapest base(s) for number "<<a<<":";
            for(int j=2;j<=36;j++){
                cout<<(res==rd[j]?" "+to_string(j):"");
            }
            cout<<"\n";
        }
    }
}
// 將十進位值傳成 n 進位，再計算各自的價位進行加總，找出最小值