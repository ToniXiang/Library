// AC (7ms, 348KB)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n,n1;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>n1;
        vector<double>v;
        v.resize(n1);
        for(int j=0;j<n1;j++){
            cin>>v[j];
        }
        sort(v.begin(),v.end());
        double prev = v[0];
        int count = 1;
        for(int i=1;i<n1;i++){
            if(prev+2>=v[i])continue;
            count++;
            prev = v[i];
        }
        // 0.5 1 3 3.5 5
        // 0.5 1 [0.5<->2.5]
        // 3 3.5 5 [3<->5]

        // 0.8 1.3 1.9 5.1 6 6.6
        // 0.8 1.3 1.9 [0.8<->2.8]
        // 5.1 6 6.6  [5.1<->7.1]
        cout << count << "\n";
    }
    return 0;
}