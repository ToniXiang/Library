#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
struct Data{
    double a;
    double b;
};
bool cmp(Data& x,Data& y){
    if (fabs(x.a) < 1e-9) return false;
    if (fabs(y.a) < 1e-9) return true;
    double x1=x.a/(x.a+x.b);
    double y1=y.a/(y.a+y.b);
    return x1<y1;
}
int gcd(int a,int b){
    return a==1?b:a%b==0?b:gcd(b,a%b);
}
typedef priority_queue<Data,vector<Data>,decltype(&cmp)>Pq;
void solove(int m,Pq& pq){
    int up=0,down=0;
    while(m--){
        Data cur=pq.top();
        pq.pop();
        up+=cur.a;
        down+=cur.a+cur.b;
    }
    if(fabs(up) < 1e-9)cout<<"0"<<endl;
    else if(up%down==0)cout<<up/down<<endl;
    else{
        int com=gcd(up,down);
        cout<<up/com<<"/"<<down/com<<endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    double a,b;
    while(cin>>n>>m){
        Pq pq_a(&cmp),pq_b(&cmp);
        while(n--){
            cin>>a>>b;
            pq_a.push({a,b});
            pq_b.push({b,a});
        }
        solove(m,pq_a);
        solove(m,pq_b);
    }
    return 0;
}