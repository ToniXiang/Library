#include<iostream>
#include<vector>
#include<queue>
#include<sstream>
#include<math.h>
using namespace std;
struct Data {
    int pos, d, u, del;
};
typedef vector<Data> vd;
typedef long long ll;
bool cmp(const Data& a, const Data& b) {
    return a.pos>b.pos;
}
//Segment Tree 線段樹
//左節點編號為 x*2 (x<<1)，右節點則為 x * 2 + 1 (x<<1|1)
int st[4000020]={0},lazy[4000020]={0};
//區間樹的每個節點都包含了正確的信息
void push_up(int x,int left,int right){
    if(lazy[x])st[x]=right-left+1;
    else if(right!=left)st[x]=st[x*2]+st[x*2+1];
    else st[x]=0;
}
//用於更新區間樹中的節點，以處理矩形的添加和移除操作
void update(int x,int left,int right,int ul,int ur,int d){
    if (ul<=left&&right<=ur){
        lazy[x]+=d;
        push_up(x,left,right);
        return;
    }
    int mid=left+(right-left)/2;
    if(ul<=mid)update(x*2,left,mid,ul,ur,d);
    if(mid<ur)update(x*2+1,mid+1,right,ul,ur,d);
    push_up(x,left,right);
}
int main() {
    priority_queue<Data,vd,decltype(&cmp)>pq(&cmp);
    int left, D, right, U;
    string s;
    while (getline(cin,s)){
        if(s=="")break;
        if(*s.end()==' ')s.erase(s.end()-1);
        stringstream ss(s);
        ss>>left;
        ss>>D;
        ss>>right;
        ss>>U;
        pq.push({left,D+1,U,1});
        pq.push({right,D+1,U,-1});
    }
    int pre = 0;
    ll ans = 0;
    while(pq.size()>0){
        Data cur=pq.top();
        pq.pop();
        if (cur.pos!= pre){
            ans += 1LL*(cur.pos-pre)*st[1];
            pre = cur.pos;
        }
        update(1, 1, 1000000, cur.d, cur.u, cur.del);
    }
    cout<<ans<<endl;
    return 0;
}
