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
// 其實就是求奇數和，但是要注意的是，如果 a 是偶數，那麼 a++
// 如果 b 是偶數，那麼 b--，這樣就可以保證 a 和 b 都是奇數