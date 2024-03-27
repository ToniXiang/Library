//	AC (5ms, 340KB)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Data
{
    int time;
    int val;
};

int main() {
    ios_base::sync_with_stdio(false);
    int n,t,m1,n1;
    while(cin>>n){
        vector<Data>v;
        for(int i=0;i<n;i++){
            cin>>t>>m1>>n1;
            v.push_back({t,m1*n1});
        }
        sort(v.begin(),v.end(),[](Data a,Data b){
            return a.time<b.time;
        });
        for(int i=0;i<n;i++){
            if(i>0&&v[i-1].time>v[i].time)v[i].time=v[i-1].time+v[i].val/2;
            else v[i].time+=v[i].val/2;
        }
        int prev=0;
        while(true){
            int min=1E5;
            int index=-1;
            for(int j=0;j<n;j++){
                if(prev>=v[j].time&&prev-v[j].time<min){
                    min=prev-v[j].time;
                    index=j;
                }
            }
            if(index!=-1)prev+=v[index].val;
            else{
                for(int i=0;i<n;i++){
                    if(v[i].time!=1E5){
                        index=i;
                        prev=v[index].time+v[index].val;
                        break;
                    }
                }
            }
            if(index==-1)break;
            v[index].time=1E5;
        }
        cout << prev << endl;
    }
    return 0;
}