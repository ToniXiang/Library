#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    string s,s1;
    while(cin>>s>>s1){
        int num[26]={0};
        int num1[26]={0};
        for(const char&it:s){
            num[it-'a']++;
        }
        for(const char&it:s1){
            num1[it-'a']++;
        }
        for(int i=0;i<26;i++){
            int mn=min(num[i],num1[i]);
            if(mn>0){
                string buf(mn,(char)('a'+i));
                cout<<buf;
            }
        }
        cout<<"\n";
    }
    return 0;
}
// 輸出：兩個字串中共同的字母，並且按照字母順序輸出