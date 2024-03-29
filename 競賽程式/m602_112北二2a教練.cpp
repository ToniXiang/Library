// 	AC (2ms, 368KB)
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
struct point{
    double x,y;
};
bool check(point a, point b, point c) {
    if(a.x == b.x) {
        return c.x == a.x && min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
    }
    if(a.y == b.y) {
        return c.y == a.y && min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x);
    }
    double slope1 = (b.y - a.y) / (b.x - a.x);
    double slope2 = (c.y - a.y) / (c.x - a.x);
    if(abs(slope1-slope2)<1e-6){
        return true;
    }
    return false;
}
void solve(int& n,vector<point>& points){
    vector<bool> fg(n,false);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(i==j||j==k||i==k)continue;
                if(check(points[i], points[j], points[k])){
                    fg[i]=true;
                    fg[j]=true;
                    fg[k]=true;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(!fg[i]){
            cout<<points[i].x<<" "<<points[i].y<<endl;
            return;
        }
    }
    cout<<"-1 -1"<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    double x,y;
    while(cin>>n){
        vector<point> points;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            points.push_back({x,y});
        }
        solve(n,points);
    }
    return 0;
}