#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
vector<int>v;
int bs(int left,int right,int key){
    if(left>right)return right;
    int mid=left+(right-left)/2;
    if(key==v[mid])return mid;
    else if(key>v[mid])return bs(mid+1,right,key);
    else return bs(left,mid-1,key);
}
int main() {
    ios_base::sync_with_stdio(false);
    for(int i=1;i*i<=1E5;i++){
        v.push_back(i*i);
    }
    int a,b;
    while(cin>>a>>b){
        if(a==0||b==0)break;
        int a_aim=bs(0,v.size()-1,a);
        if(v[a_aim]<a)a_aim++;
        int b_aim=bs(0,v.size()-1,b);
        //cout<<v[a_aim]<<" "<<v[b_aim]<<endl;
        cout<<b_aim-a_aim+1<<endl;
    }
    return 0;
}
// 二分搜尋法
// v[a_aim] 必定大於等於 a，v[b_aim] 必定小於等於 b 
// 題目：找出在 a ~ b 之間有幾個完全平方數
// 1 4 9 16 25 36 49 64 81 100