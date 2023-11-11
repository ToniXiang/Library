#include<iostream>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    int n,n1;
    ll a,b;
    int base[36];
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<"Case "<<i<<endl;
        for(int j=0;j<36;j++){
           cin>>base[j];
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
                    val+=base[b%j];
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
//假設 base[0~10]=0、1、2、3、...、9
// 20 二進制為 10100 =>  1 + 1 =  2
// 20 三進制為 202   =>  2 + 2 =  4
// 20 四進制為 110   =>  1 + 1 =  2
// 20 五進制為  40   =>  4
// 20 六進制為  32   =>  3 + 2 =  5
// 20 七進制為  26   =>  2 + 6 =  8
// 20 八進制為  24   =>  2 + 4 =  6
// 20 九進制為  22   =>  2 + 2 =  4
//越高進制不代表"各位數總和"一定是最少