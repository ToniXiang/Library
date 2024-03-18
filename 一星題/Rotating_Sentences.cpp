#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    vector<string>v;
    string s;
    int n=0;
    while(getline(cin,s)&&s!=""){
        v.push_back(s);
        n=max((int)s.size(),n);
    }
    for(int i=0;i<n;i++){
        for(int j=v.size()-1;j>=0;j--){
            cout<<(i<v[j].size()?v[j][i]:' ');
        }
        cout<<"\n";
    }
    return 0;
}
// 紀錄每行的字串，並找出最長的字串長度
// 然後依序輸出每行的第 i 個字元，若該行沒有第 i 個字元則輸出空白。
// input(行):
// s1
// s2
// s3
// output(列):
// s3 s2 s1