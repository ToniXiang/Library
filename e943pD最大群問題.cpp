#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;
int rd=0;
unordered_map<int,vector<int>>mp;
void dfs(int cur,int total,unordered_set<int>st){
    for(auto it:mp[cur]){
        if(find(st.begin(),st.end(),it)!=st.end()){
            rd=max(total+1,rd);
            return;
        }
        st.insert(it);
        dfs(it,total+1,st);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    int n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    unordered_set<int>st;
    for(auto it:mp){
        dfs(it.first,0,st);
    }
    cout<<rd<<endl;
    return 0;
}