#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
vector<ll>num={1,1};// smaller than 1E8 have 40 fib numbers
int bs(int left,int right,ll key){
    if(left>right)return right;
    int mid=left+(right-left)/2;
    if(key==num[mid])return mid;
    else if(key>num[mid])return bs(mid+1,right,key);
    else return bs(left,mid-1,key);
}
int main() {
    ios_base::sync_with_stdio(false);
    for(int i=2;num[num.size()-1]<1E8;i++){
        num.push_back(num[i-2]+num[i-1]);
    }
    int n;
    ll n1;
    cin>>n;
    for(int j=1;j<=n;j++){
        cin>>n1;
        int aim=bs(2,39,n1);
        ll head=n1;
        string res="";
        for(int i=aim;i>=1;i--){
            if(head>=num[i]){
                res+="1";
                head-=num[i];
            }
            else{
                res+="0";
            }
        }
        cout<<n1<<" = "<<res<<" (fib)"<<endl;
    }
    return 0;
}