// 	AC (0.1s, 412KB)
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    int n,k;
    while(cin>>n>>k){
        ll w[n+2]={0},h[n+2]={0};
        ll ws=0,mid=1;
        for(int i=1;i<=n;++i){
            cin>>w[i];
            ws+=w[i];
        }
        for(int i=1;i<=n;++i){
            cin>>h[i];
            if(h[i]>h[mid])mid=i;
        }
        int wei=0;
        float deep=0;
        int left=mid,right=mid;
        while(left>=0&&right<=n){
            wei+=w[left];
            w[left]=0;
            wei+=w[right];
            w[right]=0;
            ll pos=min(h[left],h[right]);
            while(pos==h[left-1]){
                left--;
                wei+=w[left];
                w[left]=0;
            }
            while(pos==h[right+1]){
                right++;
                wei+=w[right];
                w[right]=0;
            }
            if(h[left-1]>h[right+1]){
                ll volume=(pos-h[left-1])*ws*wei;
                if(volume<=k){
                    k-=volume;
                    deep+=(pos-h[left-1]);
                }
                else{
                    deep+=(float)k/(float)volume*(float)(pos-h[left-1]);
                    break;
                }
                left--;
            }
            else{
                ll volume=(pos-h[right+1])*ws*wei;
                if(volume<=k){
                    k-=volume;
                    deep+=(pos-h[right+1]);
                }
                else{
                    deep+=((float)k/(float)volume)*(float)(pos-h[right+1]);
                    break;
                }
                right++;
            }
        }
        cout<<fixed<<setprecision(1)<<deep<<endl;
    }
    return 0;
}