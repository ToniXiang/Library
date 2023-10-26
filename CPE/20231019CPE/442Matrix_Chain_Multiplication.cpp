#include<iostream>
#include<unordered_map>
#include<stack>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
int main() {
    ios_base::sync_with_stdio(false);
    int n,a,b;
    char ch;
    string s;
    cin>>n;
    unordered_map<char,pii>mp;
    mp['(']={0,0};
    while(n--){
        cin>>ch>>a>>b;
        mp[ch]={a,b};
    }
    while(cin>>s){
        if(s.size()==1){
            cout<<"0\n";
            break;
        }
        stack<pii>sk;
        vector<pii>v;
        long long res=0;
        bool fg=1;
        for(char it:s){
            if(it==')'){
                v.clear();
                while(sk.top().first!=0){
                    v.push_back(sk.top());
                    sk.pop();
                }
                sk.pop();
                if(v[1].second==v[0].first){
                    res+=v[1].first*v[1].second*v[0].second;
                    sk.push({v[1].first,v[0].second});
                }
                else{
                    fg^=1;
                    break;
                }
            }
            else{
                sk.push(mp[it]);
            }
        }
        cout<<(fg?to_string(res):"error")<<endl;
    }
    return 0;
}