//	AC (0.6s, 336KB)
#include<iostream>
#include<unordered_map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    double a,b;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>a>>b;
            unordered_map<double,int>mp;
            int rd=-1;
            string res=to_string((int)(a/b));
            a-=(int)(a/b)*b;
            if(a!=0){
                res+=".";
                rd=res.size();
                mp[a]=res.size();
                a*=10;
            }
            int count=0;
            while(true)
            {
                if(a==0){
                    res+="(0)";
                    break;
                }
                res+=to_string((int)(a/b));
                a-=(int)(a/b)*b;
                if(mp.count(a)){
                    res.insert(mp[a],"(");
                    res+=")";
                    break;
                }
                mp[a]=res.size();
                a*=10;
                if(++count==50){
                    res.insert(rd,"(");
                    res+="...)";
                    break;
                }
            }          
            cout<<res<<endl;
        }
    }
    return 0;
}