// AC (2ms, 356KB)
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
struct card
{
    double pos;
    double high;
};
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    double p,h;
    while(cin>>n){
        vector<card> cards;
        for(int i=0;i<n;i++){
            cin>>p>>h;
            cards.push_back({p,h});
        }
        sort(cards.begin(),cards.end(),[](card a,card b){
            return a.pos<b.pos;
        });
        int rd=-1;
        for(int i=0;i<n-1;i++){
            if(pow(cards[i].high,2)-pow(cards[i+1].pos
            -cards[i].pos,2)<pow(cards[i+1].high/2,2)){
                rd=cards[i+1].pos;
                break;
            }
        }
        cout<<rd<<endl;
    }
    return 0;
}
// pow(hi,2)-pow(xi+1-xi,2)>=pow(hi+1/2,2)
// 才可以推倒骨牌