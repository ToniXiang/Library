// AC (2ms, 344KB) 
#include<iostream>
#include<vector>
using namespace std;
void flip(vector<vector<bool>>&num,int x,int y){
    int x1=x-1,y1=y-1;
    int x2=x+1,y2=y+1;
    for(int i=x1;i<=x2;i++){
        for(int j=y1;j<=y2;j++){
            num[i][j]=!num[i][j];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    bool val;
    while(cin>>n>>m){
        vector<vector<bool>>num;
        for(int i=0;i<n;i++){
            vector<bool>temp;
            for(int j=0;j<m;j++){
                cin>>val;
                temp.push_back(val);    
            }
            num.push_back(temp);
        }
        int flips=0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(num[i][j]) {
                    if(i + 2 < n && j + 2 < m) {
                        flip(num, i + 1, j + 1);
                        flips++;
                    } else {
                        flips = -1;
                        break;
                    }
                }
            }
            if(flips == -1) {
                break;
            }
        }
        cout << flips << endl;
    }
    return 0;
}