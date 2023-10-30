// 	AC (58ms, 872KB)
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
#define sc set<char>
#define vs vector<sc>
#define vc vector<char>
#define vpii vector<pair<int,int>>
vpii num;
int n,n2,cur_total;
bool cod;
void dfs(int cur_n,vector<sc>col,vector<sc>row,vector<sc>dgv,vector<vc>mp){
    if(cur_n==cur_total){
        cod=true;
       for(int i=0;i<n2;i++){
            for(int j=0;j<n2;j++){
                cout<<mp[i][j]<<" ";
            }
            cout<<"\n";
        }
        return;
    }
    int cur_col=num[cur_n].first;
    int cur_row=num[cur_n].second;
    for(char i='1';i<=(char)(n2+'0');i++){
        bool fg=col[cur_col].count(i);
        bool fg1=row[cur_row].count(i);
        bool fg2=dgv[(cur_col/n)*n+(cur_row/n)].count(i);
        if(!(fg||fg1||fg2)){
            col[cur_col].insert(i);
            row[cur_row].insert(i);
            dgv[(cur_col/n)*n+(cur_row/n)].insert(i);
            mp[cur_col][cur_row]=i;
            if(!cod)dfs(cur_n+1,col,row,dgv,mp);
            mp[cur_col][cur_row]='0';
            col[cur_col].erase(i);
            row[cur_row].erase(i);
            dgv[(cur_col/n)*n+(cur_row/n)].erase(i);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    char s;
    while(cin>>n){
        num.clear();
        cod=false;
        n2=n*n;
        cur_total=0;
        vector<vc>mp(n2,vc(n2));
        vector<sc>col(n2,sc()),row(n2,sc()),dgv(n2,sc());
        for(int i=0;i<n2;i++){
            for(int j=0;j<n2;j++){
                if(cin>>s,s){
                    mp[i][j]=s;
                    if(s!='0'){
                        col[i].insert(s);
                        row[j].insert(s);
                        dgv[(i/n)*n+(j/n)].insert(s);
                    }
                    else{
                        num.push_back({i,j});
                    }
                }
            }
        }
        cur_total=num.size();
        if(cur_total!=0)dfs(0,col,row,dgv,mp);
        if(!cod)cout<<"NO SOLUTION"<<endl;
    }
    return 0;
}
/*
3
060104050
008305600
200000001
800407006
006000300
700901004
500000002
007206900
040508070

3
060104050
008305600
200000001
800407006
006000300
700901004
500000002
007206900
040508070
*/