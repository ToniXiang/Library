#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
constexpr ll mod=1E9+7;
typedef vector<vector<ll>> vvl;
int tran[3][3]={{0,1,0},{0,0,1},{1,0,2}};
vvl mult(vvl x,vvl y){
    vvl res={{0,0,0},{0,0,0},{0,0,0}};
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            for(int k=0;k<3;++k){
                res[i][j]=(res[i][j]+x[i][k]*y[k][j])%mod;
            }
        }
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    ll n;
    while(cin>>n){
        vvl mtr(3, vector<ll>(3)),res(3, vector<ll>(3));
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                mtr[i][j]=tran[i][j];
                res[i][j]=tran[i][j];
            }
        }
        n--;
        while(n!=0){
            if((n&1)==1)res=mult(res,mtr);
            mtr=mult(mtr,mtr);
            n>>=1;
        }
        cout<<(res[0][0]+res[0][2])%mod<<endl;
    }
    return 0;
}