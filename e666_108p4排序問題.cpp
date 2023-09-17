//	AC (0.6s, 336KB)
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main() {
    int n,m,aim;
    char ch;
    //ws 作用:跳開開頭的空白
    while(cin>>n>>m>>ws){
        map<char,int>mp;
        while ((ch=getchar()) != EOF&& ch != '\n')
        {
            mp[ch]++;
        }
        vector<pair<char,int>>v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[](const auto&a,const auto&b) {return a.first< b.first;});
        int* nums=new int[mp.size()];
        int index=0;
        for(const auto&it:v){
            nums[index]=0;
            nums[index]+=it.second;
            if(index>0)nums[index]+=nums[index-1];
            index++;
        }
        for(int i=0;i<m;i++){
            cin>>aim;
            for(int j=0;j<mp.size();j++){
                if(aim<=nums[j]){
                    putchar(v[j].first);
                    break;
                }
            }
        }
        putchar('\n');
    }
    return 0;
}