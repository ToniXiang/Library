//  AC (13ms, 380KB)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Point{
    int x,y;
    Point(int x,int y):x(x),y(y){}
};
int main() {
    ios_base::sync_with_stdio(false);
    vector<Point> v;
    int m,n;
    string s;
    cin>>m>>n;
    cin.ignore();
    getline(cin,s);
    auto newend=remove(s.begin(),s.end(),' ');
    s.erase(newend,s.end());
    char mp[m][n];
    int p=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mp[i][j];
            if(mp[i][j]=='.'){
                p++;
                v.push_back(Point(i,j));
            }
        }
    }
    p=(p-s.size())/2;
    for(int i=0;i<s.size();i++){
        int x=v[p+i].x,y=v[p+i].y;
        mp[x][y]=s[i];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<mp[i][j];
        }
        cout<<endl;
    }
    return 0;
}