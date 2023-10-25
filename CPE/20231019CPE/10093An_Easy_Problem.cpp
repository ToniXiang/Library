#include<iostream>
using namespace std;
int getc(char ch){
    if(ch>='a'&&ch<='z')return ch-'a'+36;
    else if(ch>='A'&&ch<='Z')return ch-'A'+10;
    else if(ch>='0'&&ch<='9')return ch-'0';
    else return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    string s;
    while(getline(cin,s)){
        int base=1,total=0;
        for(const char&it:s){
            int tmp=getc(it);
            total+=tmp;
            base=max(tmp,base);
        }
        int i=base;
        for(;i<62;i++){
            if(!(total%i)){
                cout<<i+1<<endl;
                break;
            }
        }
        if(i==62)cout<<"such number is impossible!"<<endl;
    }
    return 0;
}