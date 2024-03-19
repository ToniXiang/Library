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
        vector<Data> v;
        while(N--){
            cin >> temp;
            v.push_back({temp, temp % M, temp & 0x1});
        }
        sort(v.begin(), v.end(), cmp);
        for(auto &i : v) cout << i.num << "\n";
    }
    return 0;
}
// precede (再前面) ascending order (遞增排序)
//
// the N numbers in ascending order of their modulo M value.
// (that is their modulo M value is the same) 
// ... then the odd number will precede the even number.
// ... then the larger odd number will precede the smaller odd number.
// ... then the smaller even number will precede the larger even number.
//
// 這題的 mod M 值是從遞增排序
// 如果 mod M 相同，那麼奇數會排在前面
// 如果都是奇數，那麼大的數字會排在前面
// 如果都是偶數，那麼小的數字會排在前面