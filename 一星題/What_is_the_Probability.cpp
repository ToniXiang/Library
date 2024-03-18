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
    // Probability(機率)的計算
    // a 表示玩家數，b 表示一次成功事件發生的機率，c (c ≤ a) 表示要確定獲勝機率的玩家的序列 (序列號碼從 1 到 a)。
    // 成功機率 b 轉換成失敗機率 1-b
    // a 回合中第 c 個人獲勝的機率為：每個人都失敗的機率 * 第 c 個位置上成功的機率
    // 得到第 c 個人的獲勝機率，需要將第 c 個人在每個回合的機率相加(等比級數)
    return 0;
}