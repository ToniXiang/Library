#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n,a,c;
    double b;
    while(cin>>n){
        while(n--){
            cin>>a>>b>>c;
            cout<<fixed<<setprecision(4)<<(b==0?0.0000:(pow(1-b,c-1)*b)/(1-pow(1-b,a)))<<endl;
        }
    }
    //成功機率 b 轉換成失敗機率 1-b
    //假設 a 回合中第 c 個人獲勝的機率為：每個人都失敗的機率*第 c 個位置上成功的機率
    //得到第 c 個人的獲勝機率，需要將第 c 個人在每個回合的機率相加(等比級數)
    return 0;
}