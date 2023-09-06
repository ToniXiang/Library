#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;
typedef unordered_set<int> usi;
/*
4 4
1 2
2 3
3 1
1 4
1->2、3、4
2->1、3、4
3->1、2
4->1
共同有1、2、3共3個
*/
int main() {
    ios_base::sync_with_stdio(false);
    int n, m, a, b;
    cin >> n >> m;
    unordered_set<int> friends[n + 1];
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        friends[a].insert(b);
        friends[b].insert(a);
    }
    int maxGroupSize = 0; 
    for (int i = 1; i <= n; i++) {
        int total = 0;    
        for (int friendId : friends[i]) {
            total += friends[friendId].count(i);
        }      
        maxGroupSize = max(maxGroupSize, total);
    } 
    cout << maxGroupSize << endl; 
    return 0;
}