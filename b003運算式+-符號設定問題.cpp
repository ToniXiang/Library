//	AC (2ms, 328KB)
#include<iostream>
#include<math.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int k;
    while(cin>>k){
        k=abs(k);
        //n^2+n-2k>=0 已知k,公式求解n
        int n=(-1+sqrt(1-4*1*(-2*k)))/(2*1);
        //數列級數和 (首+末)*項數/2
        int sum=n*(1+n)/2;
        if(sum<k)sum+=++n;
        while((sum-k)%2!=0){
            sum+=++n;
        }
        cout<<n<<endl;
    }
    return 0;
}