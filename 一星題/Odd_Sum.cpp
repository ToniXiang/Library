#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n,a,b;
    while(cin>>n){
        int cnt=1;
        while(n--){
            cin>>a>>b;
            if((a&1)==0)a++;
            if((b&1)==0)b--;
            int rang=(b-a)/2+1;
            cout<<"Case "<<cnt++<<": "<<rang*(a+b)/2<<endl;
        }
    }
    return 0;
}
//其實就是求奇數和，但是要注意的是，如果a是偶數，那麼a++
//如果b是偶數，那麼b--，這樣就可以保證a和b都是奇數
//然後就是求奇數和了，注意一下求和公式。