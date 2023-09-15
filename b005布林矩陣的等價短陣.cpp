#include<iostream>
#include<vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    while (cin>>n)
    {
        bool mp[100][100];
        bool col[100]={false},row[100]={false};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>mp[i][j];
                col[i]^=mp[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                row[i]^=mp[j][i];
            }
        }
        int rd_c=-1,rd_r=-1;
        int n_c=0,n_r=0;
        for(int i=0;i<n;i++){
            if(col[i])rd_c=i,n_c++;
            if(row[i])rd_r=i,n_r++;
        }
        if(n_c==0&&n_r==0){
            cout<<"OK"<<endl;
        }
        else if(n_c==1&&n_r==1){
            cout<<"Change bit ("<<rd_c+1<<","<<rd_r+1<<")"<<endl;
        }
        else{
            cout<<"Corrupt"<<endl;
        }
    }
    return 0;
}