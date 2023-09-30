#include<iostream>
#include<sstream>
#include<algorithm>
#include<unordered_set>
using namespace std;
void pre(stringstream&ss){
    string s;
    getline(cin,s);
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    ss=stringstream(s);
}
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    string data;
    stringstream ss,ss1;
    cin>>n;
    cin.ignore();
    while (n--)
    {
        unordered_set<string>st;
        pre(ss);
        while(getline(ss,data,',')){
            st.insert(data);
        }
        int res=0;
        pre(ss1);
        while(getline(ss1,data,',')){
            if(st.count(data)>=1)res++;
        }
        cout<<res<<endl;
    }
    return 0;
}