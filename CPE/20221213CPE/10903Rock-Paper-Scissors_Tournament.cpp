#include<iostream>
#include<math.h>
using namespace std;
struct Data
{
    double win;
    double lose;
};

int main() {
    ios_base::sync_with_stdio(false);
    int n,k,p1,p2;
    string m1,m2;
    while(cin>>n>>k){
        if(n==0)break;
        Data nums[n]={{0,0}};
        int len=k*n*(n-1)/2;
        for(int i=0;i<len;i++){
            cin>>p1>>m1>>p2>>m2;
            p1-=1;
            p2-=1;
            if(m1[0]==m2[0])continue;
            if((m1[0]=='r'&&m2[0]=='s')||(m1[0]=='p'&&m2[0]=='r')||(m1[0]=='s'&&m2[0]=='p')){
                nums[p1].win++;
                nums[p2].lose++;
            }
            else{
                nums[p2].win++;
                nums[p1].lose++;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i].win+nums[i].lose==0){
                cout<<"-"<<endl;
            }
            else{
                string res=to_string(round(nums[i].win/(nums[i].win+nums[i].lose)*1E3)/1E3);
                cout<<res.substr(0,5)<<endl;
            }
        }
        cout<<"\r\n";
    }
    return 0;
}