#include<iostream>
#include<unordered_map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n,tmp;
    string s;
    while(cin>>n&&n!=0){
        unordered_map<string,int>mp;
        mp["top"] = 1;
        mp["north"] = 2;
        mp["west"] = 3;
        mp["east"] = 4;
        mp["south"] = 5;
        mp["bottom"] = 6;
        while(n--){
            cin>>s;
            if(s=="north"){             //北轉
                tmp=mp["north"];        //北>底 底>南  南>頂  頂>北
                mp["north"]=mp["top"];  //記：北 <-> 南
                mp["top"]=mp["south"];
                mp["south"]=mp["bottom"];
                mp["bottom"]=tmp;
            }
            else if(s=="east"){         //東轉
                tmp=mp["east"];         //東>底 底>西  西>頂  頂>東
                mp["east"]=mp["top"];   //記：東 <-> 西
                mp["top"]=mp["west"];
                mp["west"]=mp["bottom"];
                mp["bottom"]=tmp;
            }
            else if(s=="south"){        //南轉
                tmp=mp["south"];        //南>底 底>北  北>頂  頂>南
                mp["south"]=mp["top"];  //記：南 <-> 北
                mp["top"]=mp["north"];
                mp["north"]=mp["bottom"];
                mp["bottom"]=tmp;
            }
            else if(s=="west"){         //西轉
                tmp=mp["west"];         //西>底 底>東  東>頂  頂>西
                mp["west"]=mp["top"];   //記：西 <-> 東
                mp["top"]=mp["east"];
                mp["east"]=mp["bottom"];
                mp["bottom"]=tmp;
            }
        }
        cout<<mp["top"]<<endl;
    }
    return 0;
}