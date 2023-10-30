#include<iostream>
#include<vector>
using namespace std;
int gcd(int a,int b){
    if(a==1)return b;
    else return a%b==0?b:gcd(b,a%b);
}
void deal(int& val,int count,string&res){
    int record = 0;
    while (val % count == 0){
        val /= count;
        record++;
    }
    if (record >= 1) res+= record == 1 ? to_string(count)+"*" : to_string(count)+"^"+to_string(record)+"*";
}
int main() {
    ios_base::sync_with_stdio(false);
    vector<bool>isprime(65536, true);
    isprime[0]=isprime[1]=false;
    for(int j=2;j*j<65536;j++){
        if(isprime[j]){
            for(int k=j*j;k<65536;k+=j){
                isprime[k]=false;
            }
        }
    }
    int n,a,b;
    cin>>n;
    while(n--){
        cin>>a>>b;
        int com=gcd(a,b);
        string res="";
        int c=5;
        deal(a,2,res);
        deal(a,3,res);
        while(a>=c){
            if(a%c==0)deal(a,c,res);
            if(a%(c+2)==0)deal(a,c+2,res);
            c+=6;
        }
        res.erase(res.end()-1);
        cout<<res<<" , "<<com<<" , "<<(isprime[com]?"Y":"N")<<endl;
    }
    return 0;
}