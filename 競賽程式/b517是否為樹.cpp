#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<sstream>
using namespace std;
unordered_set<int>st;
unordered_map<int,vector<int>>mp;
unordered_map<int,bool>rd;
int dfs(int index,int parent){
    if(rd[index])return 0;
    int total=1;
    rd[index]=true;
    for(const int next:mp[index]){
        if(next==parent)continue;
        total+=dfs(next,index);
    }
    return total;
}
int main() {
    ios_base::sync_with_stdio(false);
    int n,a,b;
    cin>>n;
    cin.ignore();
    char del;
    while(n--){
        mp.clear();
        st.clear();
        string s,s1,buf;
        getline(cin,s);
        bool isSpace=false;
        for (char ch : s) {
            if (ch != ' ' || !isSpace) {
                s1 += ch;
            }
            isSpace = (ch == ' ');
        }
        stringstream ss(s1);
        int c=0;
        while(getline(ss,buf,' ')){
            stringstream ss1(buf);
            ss1>>a>>del>>b;
            mp[a].push_back(b);
            mp[b].push_back(a);
            st.insert(a);
            st.insert(b);
            c++;
        }
        if(c+1!=st.size()){
            cout<<"F\n";
            continue;
        }
        bool fg=true;
        for(const int it:st){
            rd.clear();
            if(dfs(it,-1)!=st.size()){
                fg=false;
                break;
            }
        }
        cout<<(fg?"T":"F")<<endl;
    }
    return 0;
}