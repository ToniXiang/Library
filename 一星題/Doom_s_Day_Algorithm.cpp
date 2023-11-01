#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    string days[7] ={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
    int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int n,a,b;
    while(cin>>n){
        while(n--){
            cin>>a>>b;
            int day=b;
            for(int i=0;i<a-1;i++){
                day+=months[i];
            }
            cout<<days[day%7-1]<<endl;
        }
    }
    return 0;
}