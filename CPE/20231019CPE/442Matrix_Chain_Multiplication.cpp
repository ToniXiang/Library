#include<iostream>
#include<unordered_map>
#include<stack>
#include<set>
#include<algorithm>
#define w st.begin()
#define x st.end()
#define y st1.begin()
#define z st1.end()
#define inst(xx) inserter(xx,xx.begin())
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n,a,b;
    char ch;
    string s;
    cin>>n;
    unordered_map<char,set<int>>mp;
    while(n--){
        cin>>ch>>a>>b;
        mp[ch]={a,b};
    }
    while(cin>>s){
        if(s.size()==1){
            cout<<"0\n";
            continue;
        }
        s+=")";
        stack<set<int>>sk;
        stack<char>bf;
        int res=0;
        bool fg=true;
        for(char it:s){
            switch(it){
                case ')':
                    while(bf.size()!=0&&bf.top()!='('){
                        if(sk.size()==0){
                            sk.push(mp[bf.top()]);
                        }
                        else{
                            set<int> st=sk.top();
                            set<int> st1=mp[bf.top()];
                            set<int> sdSet;
                            set_symmetric_difference(w,x,y,z,inst(sdSet));
                            set<int>unionSet;
                            set_union(w,x,y,z,inst(unionSet));
                            sk.pop();
                            if(sdSet.size()==2){
                                int m=1;
                                for_each(unionSet.begin(), unionSet.end(), [&m](int item) {
                                    m*=item;
                                });
                                res+=m;
                                sk.push(sdSet);
                            }
                            else{
                                fg=false;
                            }
                        }
                        bf.pop();
                    }
                    bf.pop();
                    break;
                default:
                    bf.push(it);
            }
            if(!fg)break;
        }
        cout<<(fg?to_string(res):"error")<<endl;
    }
    return 0;
}