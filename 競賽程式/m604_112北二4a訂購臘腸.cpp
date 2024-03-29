// NA (score:30%)
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n,a;
    while(cin>>n){
        int num[n];
        vector<vector<int>>mp;
        for(int i=0;i<n;i++){
            cin>>num[i];
        }
        for(int i=0;i<n;i++){
            vector<int>tmp;
            for(int j=0;j<num[i];j++){
                cin>>a;
                tmp.push_back(a);
            }
            mp.push_back(tmp);
        }
        sort(mp.begin(),mp.end(),[](vector<int>&a,vector<int>&b){
            return a.size()<b.size();
        });
        int count=1;
        int rd=0;
        string s="";
        stringstream ss;
        for(int i=0;i<n;i++){
            if(rd==0){
                for(int j=mp[i].size()-1;j>=0;j--){
                s+=to_string(mp[i][j])+" ";
                if(++rd==count){
                    ss<<s.substr(0,s.size()-1)<<endl;
                    count++;
                    rd=0;
                    s="";
                    }
                }
            }
            else{
                for(int j=0;j<mp[i].size();j++){
                    s+=to_string(mp[i][j])+" ";
                    if(++rd==count){
                        ss<<s.substr(0,s.size()-1)<<endl;
                        count++;
                        rd=0;
                        s="";
                    }
                }
                if(rd!=0)break;
            }
            if(rd==count){
                ss<<s.substr(0,s.size()-1)<<endl;
                count++;
                rd=0;
                s="";
            }
        }
        cout<<(rd==0?ss.str():"-1\r\n");
    }
    return 0;
}