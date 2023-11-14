#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
vector<string>str={"","shata","hajar","lakh","kuti","shata","hajar","lakh","kuti"};
vector<int>number={100,10,100,100,100,10,100,100,100};
int main() {
    ios_base::sync_with_stdio(false);
    ll n;
    int cnt1=0;
    while(cin>>n){
        string res="",base="";
        int cnt=0;
        if(n==0){
            cout<<++cnt1<<". 0"<<endl;
            continue;
        }
        while(n>0){     
            int remainder=n%number[cnt];
            n/=number[cnt];
            if(remainder>0){
                res=" "+to_string(remainder)+" "+str[cnt]+res;
            }
            else if(str[cnt]=="kuti"){
                res=" kuti"+res;
            }
            cnt++;
        }
        cout<<++cnt1<<"."<<res<<endl;
    }
    return 0;
}