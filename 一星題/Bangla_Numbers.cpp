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
// 1E2 shata
// 1E3 hajar
// 1E5 lakh
// 1E7 kuti
// 1E9 shata (kuti)
// 1E10 hajar (kuti)
// 1E12 lakh (kuti)
// 1E14 kuti (kuti)
// 1. 9 kuti 99 lakh 99 hajar 9 shata 99 kuti 99 lakh 99 hajar 9 shata 99