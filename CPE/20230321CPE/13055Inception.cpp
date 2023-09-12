#include<iostream>
#include<stack>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    stack<string>sk;
    int n;
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s=="Sleep"){
            cin>>s;
            sk.push(s);
        }
        else if(s=="Test"){            
            if(sk.size()!=0)cout<<sk.top()<<endl;
            else cout<<"Not in a dream"<<endl;
        }
        else if(s=="Kick"){
            if(sk.size()!=0)sk.pop();
        }
    }
    return 0;
}