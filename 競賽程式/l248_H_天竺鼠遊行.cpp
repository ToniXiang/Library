//	AC (0.4s, 15.6MB)
#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;
typedef long long ll;
int n,k,p;
vector<ll>h(1000005);
bool check(ll x){
    int cnt=0;
    for(int i=k-1;i<n;++i){
        if(h[i]<=x){
            cnt++;
            i+=k-1;
        }
    }
    return cnt>=p;
}
int main() {
    ios_base::sync_with_stdio(false);
    while(cin>>n>>k>>p){
        vector<ll>v(n);
        for(int i=0;i<n;++i){
            cin>>v[i];
        }
        sort(v.begin(),v.end(),[](const int&a,const int&b){return a<b;});
        h.clear();
        deque<int>dq;
        int d=min(k-1,2);
        for(int i=0;i<k-1;++i){
            if(i-d>=0){
                int diff=v[i]-v[i-d];
                auto it=lower_bound(dq.begin(),dq.end(),diff);
                dq.insert(it,diff);
            }
        }
        for(int i=k-1;i<n;++i){
            if(i-d>=0){
                ll diff=v[i]-v[i-d];
                auto it=lower_bound(dq.begin(),dq.end(),diff);
                dq.insert(it,diff);
            }
            if (i-k>=0) {
                int old_diff=v[i-k+d]-v[i-k];
                auto it=lower_bound(dq.begin(),dq.end(),old_diff);
                dq.erase(it);
            }
            h[i]=dq.back();
            //cout<<h[i]<<endl;
        }
        ll left=0,right=1E9,res=-1;
        while(left<=right){
            ll mid=left+((right-left)>>1);
            if(check(mid)){
                res=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}