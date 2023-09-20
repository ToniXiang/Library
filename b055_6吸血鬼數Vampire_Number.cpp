//	AC (2ms, 356KB)
#include<iostream>
#include<math.h>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;
int fpow(int m,int n){
    if(n==0)return 1;
    else if(n==1)return m;
    else if((n%2)==1)return m*fpow(m*m,n/2);
    return fpow(m*m,n/2);
}
int countZeros(int num) {
    int count = 0;
    while (num != 0) {
        if (num % 10 == 0) {
            count++;
        }
        num /= 10;
    }
    return count;
}
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    while(cin>>n){
        n/=2;
        int n1=fpow(10,n)/10;
        int n2=999999999%(n1*10);
        unordered_map<string,string>mp;
        for(int i=n1;i<=n2;i++){
            for(int j=n1+1;j<=n2;j+=(10-j%10)){
                int val=i*j;
                if(countZeros(val)!=1)continue;
                string str_1=to_string(i)+to_string(j);
                string str_2=to_string(val);
                sort(str_1.begin(),str_1.end());
                sort(str_2.begin(),str_2.end());
                if(str_1==str_2){
                    if(mp.count(str_2))continue;
                    mp[str_2]=to_string(val);
                }
            }
        }
        vector<pair<string,string>>res(mp.begin(),mp.end());
        sort(res.begin(),res.end(),[](const auto&a,const auto&b){return a.second<b.second;});
        for(const auto&it:res){
            cout<<it.second<<endl;
        }
    }
    return 0;
}