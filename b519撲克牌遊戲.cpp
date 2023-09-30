#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num[5]={0};
        int num1[5]={0};
        map<int,int>mp;
        for(int j=0;j<5;j++){
            cin>>num[j];
            int val=num[j]%13==0?13:num[j]%13;
            num1[j]=val;
            mp[val]++;
        }
        sort(num,num+5);
        sort(num1,num1+5);
        bool fg=false,fg1=false,fg2=false,fg3=false;
        for(const auto it:mp){
            if(it.second==4)fg=true;
            else if(it.second==3)fg1=true;
            else if(it.second==2&&!fg2)fg2=true;
            else if(it.second==2)fg3=true;
        }
        if(num[0]+1==num[1]&&num[1]+1==num[2]&&num[2]+1==num[3]&&num[3]+1==num[4]){
            cout<<"7"<<endl;
        }
        else if(fg){
            cout<<"6"<<endl;
        }
        else if(fg1&&fg2){
            cout<<"5"<<endl;
        }
        else if(num1[0]+1==num1[1]&&num1[1]+1==num1[2]&&num1[2]+1==num1[3]&&num1[3]+1==num1[4]){
            cout<<"4"<<endl;
        }
        else if(fg1){
            cout<<"3"<<endl;
        }
        else if(fg2&&fg3){
            cout<<"2"<<endl;
        }
        else if(fg2){
            cout<<"1"<<endl;
        }
        else{
            cout<<"0"<<endl;
        }
    }
    cin.get();
    return 0;
}