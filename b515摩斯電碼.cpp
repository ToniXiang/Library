#include<iostream>
#include<unordered_map>
#include<sstream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    unordered_map<string,string> mp = {    
    {".-","A"}      ,   {"-...","B"}    ,   {"-.-.","C"}    ,   {"-..","D"}     ,
    {".","E"}       ,   {"..-.","F"}    ,   {"--.","G"}     ,   {"....","H"}    ,
    {"..","I"}      ,   {".---","J"}    ,   {"-.-","K"}     ,   {".-..","L"}    ,
    {"--","M"}      ,   {"-.","N"}      ,   {"---","O"}     ,   {".--.","P"}    ,
    {"--.-","Q"}    ,   {".-.","R"}     ,   {"...","S"}     ,   {"-","T"}       ,
    {"..-","U"}     ,   {"...-","V"}    ,   {".--","W"}     ,   {"-..-","X"}    ,
    {"-.--","Y"}    ,   {"--..","Z"}
    };
    int n;
    string s,buf;
    cin>>n;
    cin.ignore();
    while(n--){
        getline(cin,s);
        stringstream ss(s);
        while(getline(ss,buf,' ')){
            cout<<mp[buf];
        }
        cout<<"\n";
    }
    return 0;
}