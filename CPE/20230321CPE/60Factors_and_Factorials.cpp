#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Data
{
    int num;
    int val;
};
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    vector<Data>org{{2,0},{3,0}};
    for(int i=5;i<=100;i++){
        bool fg=false;
        for(int j=2;j<i;j++){
            if(i%j==0){
                fg=true;
                break;
            }
        }
        if(!fg)org.push_back({i,0});
    }
    while (cin>>n)
    {
        if(n==0)break;
        vector<Data>v=org;
        for(int i=2;i<=n;i++){
            int a=i,j=0;
            while (j<v.size())
            {
                if(a%v[j].num==0){
                    v[j].val++;
                    a/=v[j].num;
                    if(a==1)break;
                }
                else{
                    j++;
                }
            }
        }
        cout<<n<<"! = ";
        int rd=-1;
        for(int i=v.size()-1;i>=0;i--){
            if(v[i].val!=0){
                rd=i;
                break;
            }
        }
        for(int i=0;i<=rd;i++){
            cout<<v[i].val<<" ";
            if((i+1)%15==0)cout<<"\r\n";
        }
        cout<<endl;
    }
    return 0;
}