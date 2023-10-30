#include<iostream>
#include<vector>
#include<queue>
#include<sstream>
#include<math.h>
using namespace std;
struct Data {
    int pos, d, u, del;
};
bool cmp(const Data& a, const Data& b) {
    return a.pos>b.pos;
}
typedef vector<Data> vd;
using pq_type = priority_queue<Data, vd, decltype(&cmp)>;
//Segment Tree 線段樹
//左節點編號為 id*2 (id<<1)，右節點則為 id * 2 + 1 (id<<1|1)
//id * 2 + 2 不為 id << 1 | 2 ex. id = 1，1 << 1 | 2 = 2 非 2 + 2
#define id_left (id<<1)
#define id_right (id<<1)|1
int seg[(int)1E6<<2]={0},arr[(int)1E6<<2]={0};
//區間樹的每個節點都包含了正確的信息
void build(int id,int left,int right){
    if(arr[id])seg[id]=right-left+1;
    else if(left!=right)seg[id]=seg[id_left]+seg[id_right];
    else seg[id]=0;
}
//用於更新區間樹中的節點，以處理矩形的添加和移除操作
void update(int id,int left,int right,int query_left,int query_right,int del){
    if (query_left<=left&&right<=query_right){
        arr[id]+=del;
        build(id,left,right);
        return;
    }
    int mid=left+(right-left)/2;
    if(query_left<=mid)update(id_left,left,mid,query_left,query_right,del);
    if(mid<query_right)update(id_right,mid+1,right,query_left,query_right,del);
    build(id,left,right);
}
int main() {
    ios::sync_with_stdio(false);
    pq_type pq(&cmp);
    int left, down, right, up;
    string s;
    while (getline(cin,s)){
        if (s.empty()) break;
        istringstream iss(s);
        iss>>left>>down>>right>>up;
        pq.push({left,down+1,up,1});
        pq.push({right,down+1,up,-1});
    }
    int pre = 0;
    long long ans = 0;
    while(pq.size()>0){
        Data cur=pq.top();
        pq.pop();
        if (cur.pos!= pre){
            ans += 1LL*(cur.pos-pre)*seg[1];
            pre = cur.pos;
        }
        update(1,1,1E6, cur.d, cur.u, cur.del);
    }
    cout<<ans<<endl;
    return 0;
}
