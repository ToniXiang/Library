#include<iostream>
#include<vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    string s;
    vector<string>v;
    while(getline(cin,s)&&s.size()!=0){
        v.push_back(s);
    }
    int fg=0;
    for(const string&str:v){
        for(const char&it:str){
            if(it=='\"'){
                cout<<((fg&1)?"''":"``");
                fg^=1;
            }
            else{
                cout<<it;
            }
        }
        cout<<"\n";
    }
    return 0;
}