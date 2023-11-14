#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int t,n,m,q,x,y,x1,y1;
    cin>>t;
    while(t--){
        cin>>n>>m>>q;
        cout<<n<<" "<<m<<" "<<q<<endl;
        char mp[n+2][m+2]={' '};
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                cin>>mp[i][j];
            }
        }
        while(q--){
            cin>>x>>y;
            int cnt=-2;
            x1=++x;
            y1=++y;
            char aim=mp[x][y];
            bool fg=true;
            do{
                for(int i=x;i<=x1;++i){
                    if(aim!=mp[i][y]||aim!=mp[i][y1]){
                        fg=false;
                        break;
                    }
                }
                for(int i=y;i<=y1;i++){
                    if(aim!=mp[x][i]||aim!=mp[x1][i]){
                        fg=false;
                        break;
                    }
                }
                x--;
                y--;
                x1++;
                y1++;
                cnt++;
            }while(fg);
            cout<<cnt*2+1<<endl;
        }
    }
    return 0;
}