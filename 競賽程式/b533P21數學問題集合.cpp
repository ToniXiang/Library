#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
#define a st.begin()
#define b st.end()
#define c st1.begin()
#define d st1.end()
#define inst(xx) inserter(xx,xx.begin())
string p(set<int>st){
    string r="";
    for(int it:st){
        r+=to_string(it)+", ";
    }
    if(r=="")return "N, ";
    r.erase(r.end()-1);
    r.erase(r.end()-1);
    return "{"+r+"}, ";
}
int main() {
    int n;
    string s,s1;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        set<int>st;
        set<int>st1;
        bool fg=false;
        for(int j=0;j<s.size();j++){
            if(s[j]==' '||s[j]=='{')continue;
            if(s[j]==','||s[j]=='}'){
                if(!fg)st.insert(atoi(s1.c_str()));
                else st1.insert(atoi(s1.c_str()));
                s1="";
                if(s[j]=='}'){
                    fg=true;
                    j+=2;
                }
                continue;
            }
            s1+=s[j];
        }
        set<int> unionSet;
        set_union(a,b,c,d,inst(unionSet));
        set<int> intersectionSet;
        set_intersection(a,b,c,d,inst(intersectionSet));
        set<int> differenceSet;
        set_difference(a,b,c,d,inst(differenceSet));
        set<int>symmetricDifferenceSet;
        set_symmetric_difference(a,b,c,d,inst(symmetricDifferenceSet));
        string r=p(unionSet)+p(intersectionSet)+p(differenceSet)+p(symmetricDifferenceSet);
        r.erase(r.end()-1);
        r.erase(r.end()-1);
        cout<<r<<endl;
    }
    return 0;
}