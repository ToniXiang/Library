#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Data{
    int num;
    int mod;
    int Even_Odd;
};

bool cmp(const Data& a,const Data& b) {
    if(a.mod != b.mod) return a.mod < b.mod;
    if(a.Even_Odd != b.Even_Odd) return a.Even_Odd > b.Even_Odd;
    return a.Even_Odd ? a.num > b.num : a.num < b.num;
}

int main() {
    int N, M, temp;
    while(cin >> N >> M) {
        cout << N << " " << M << "\n";
        if(N == 0 && M == 0) break;
        vector<Data> v(N);
        for(auto &i : v) {
            cin >> temp;
            i = {temp, temp % M, temp & 0x1};
        }
        sort(v.begin(), v.end(), cmp);
        for(auto &i : v) cout << i.num << "\n";
    }
    return 0;
}