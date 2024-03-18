#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    string days[7] ={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
    int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int n,a,b;
    while(cin>>n){
        while(n--){
            cin>>a>>b;
            int day=b;
            for(int i=0;i<a-1;i++){
                day+=months[i];
            }
            cout<<days[(day%7!=0?day%7-1:(day-1)%7)]<<endl;
            //day=1 -> 0 (sat)
            //day=8 -> 0 (sat)
            //day=7 -> 6 (fri)
        }
    }
    return 0;
}
// 2011 年是一個，第一天從星期六開始
// 平年 2 月為 28 天，閏年的 2 月為 29 天