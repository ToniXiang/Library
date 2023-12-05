#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    while(cin>>n){
        int nums[n];
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        sort(nums,nums+n);
        int mid=nums[n/2];
        int mid1=nums[(n-1)/2];
        int res=0;
        for(int x:nums){
            if(x==mid||x==mid1)res++;
        }
        cout<<mid1<<" "<<res<<" "<<mid-mid1+1<<endl;
    }
    return 0;
}