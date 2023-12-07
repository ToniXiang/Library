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
/*
    這題的思路是，先把輸入的數據存到二維數組中，然後再進行操作
    操作的時候，先把要操作的區域擴大一圈，範圍內[1~n+1][1~m+1]，這樣就可以保證不會出界
    然後就是判斷是否是正方形了，如果不是，就繼續擴大區域，直到是正方形為止
    這題的關鍵在於，如何判斷是否是正方形，這裡我是用了一個bool變量來判斷
    如果不是正方形，就把bool變量設為false，然後跳出循環
*/