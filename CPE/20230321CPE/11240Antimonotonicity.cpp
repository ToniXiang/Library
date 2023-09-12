#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n,n1;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        cin>>n1;
        int nums[n1];
        for(int j=0;j<n1;j++){
            cin>>nums[j];
        }
        int res=1,cur=1;
        for(int j=1;j<n1;j++){
            if(cur%2==1&&nums[j-1]>nums[j]){
                cur++;
            }
            else if(cur%2==0&&nums[j-1]<nums[j]){
                cur++;
            }
            else{
                res=max(res,cur);
                cur=1;
            }
        }
        cout<<max(res,cur)<<endl;
    }
    return 0;
}